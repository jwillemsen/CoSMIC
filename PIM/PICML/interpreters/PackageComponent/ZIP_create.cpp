#include "ace/OS_NS_fcntl.h"       //for open
#include "ace/OS_NS_unistd.h"      //for close
#include "ace/SString.h"           //for ACE_CString
#include "ace/OS_NS_sys_stat.h"    //for filesize and mkdir
#include "ace/Dirent.h"
#include "ace/FILE_Connector.h"

#include "ZIP_create.h"

#define WRITEBUFFERSIZE (16384)
#define DIR_DOT "."
#define DIR_DOT_DOT ".."

int ZIP_create::compress(const std::string filename,
                         const std::string dir,
						             int compress_level,
                         int append)
{
  // append to existing zip file
  if (append == 2)
    {
      // if the file does not exist, we do not append file
      if (check_if_file_exists(filename) == false)
        append = 0;
      else
        get_exist_files_in_zip(filename, dir);
    }

  ACE_TCHAR full_path[MAXPATHLEN];
  if (ACE_OS::getcwd (full_path, sizeof(full_path)) == NULL)
    throw udm_exception (string ("Get cwd failed: ") + string (full_path));

  get_filenames(dir, full_path);

  if (ACE_OS::chdir (full_path) == -1)
    throw udm_exception (string ("chdir failed: ") + string (full_path));

  // open the zip file
  zipFile zf = zipOpen(filename.c_str (), append);
  if (zf == NULL)
    throw udm_exception (string ("There is some problem in opening the zipfile using zipOpen: " + filename));

  // add each dir passed in vector to zip file
  for(unsigned int i = 0; i < dirs_.size(); i++)
	  {
      std::string dirnameinzip = dirs_.at(i);
      std::string dirname;

      size_t loc = dirnameinzip.find (dir);
      if (loc <= dirnameinzip.length ())
          dirname = dirnameinzip.substr (loc + dir.length () + 1, dirnameinzip.length ());

      zip_fileinfo zi;

      // open the file inside zipfile
      int err = zipOpenNewFileInZip(zf, dirname.c_str (), &zi, NULL, 0, NULL, 0, NULL,
                                    (compress_level != 0) ? Z_DEFLATED : 0, compress_level);               
      if (err != ZIP_OK)
        throw udm_exception
          (string ("There is some problem in opening in zipfile using zipOpenNewFileInZip: " + dirnameinzip));
   
      // close the file inside zipfile
      err = zipCloseFileInZip(zf);
      if (err != ZIP_OK)
        throw udm_exception
          (string ("There is some problem in closing zipfile using zipCloseFileInZip: " + dirnameinzip));
    }

	void *buf = NULL;
  int size_buf = WRITEBUFFERSIZE;
  // add each file passed in vector to zip file
  for(unsigned int i = 0; i < files_.size(); i++)
	  {
      std::string filenameinzip = files_.at(i);
      std::string filename;

      size_t loc = filenameinzip.find (dir);
      if (loc <= filenameinzip.length ())
          filename = filenameinzip.substr (loc + dir.length () + 1, filenameinzip.length ());

      zip_fileinfo zi;

      // open the file inside zipfile
      int err = zipOpenNewFileInZip(zf, filename.c_str (), &zi, NULL, 0, NULL, 0, NULL,
                                    (compress_level != 0) ? Z_DEFLATED : 0, compress_level);               
      if (err != ZIP_OK)
        throw udm_exception
          (string ("There is some problem in opening zipfile using zipOpenNewFileInZip: " + filenameinzip));

      FILE *fin = fopen(filenameinzip.c_str (), "rb");
      if (fin == NULL)
        throw udm_exception
          (string ("There is some problem in opening file: " + filenameinzip));

      buf = (void*) malloc(WRITEBUFFERSIZE);     
      int size_read;
      do
        {
          // read the file and write it in the zipfile
          size_read = (int)fread(buf,1,size_buf,fin);
         
          if (size_read < size_buf)
            if (feof(fin) == 0)
              err = ZIP_ERRNO;

          if (size_read > 0)
            err = zipWriteInFileInZip(zf,buf,size_read);             
        } while ((err == ZIP_OK) && (size_read > 0));

      fclose(fin);
   
      // close the file inside zipfile
      err = zipCloseFileInZip(zf);
      if (err != ZIP_OK)
        throw udm_exception
          (string ("There is some problem in closing zipfile using zipCloseFileInZip: " + filenameinzip));
    }

  if (buf != NULL)
    free(buf);
 
  files_.clear();

  // close the zip file
  int errclose = zipClose(zf,NULL);
  if (errclose != ZIP_OK)
    throw udm_exception
      (string ("There is some problem in closing zipFile using zipClose: " + filename));
   
  return 0;
}


bool ZIP_create::check_if_file_exists(const std::string filename)
{
  FILE *filecheck;
  filecheck = fopen(filename.c_str (), "rb");
  if (filecheck == NULL)
     return false;
  else
     fclose(filecheck);
  return true;
}

void ZIP_create::get_filenames(const std::string dirname,
                               const std::string dirname_bak)
{
  if (ACE_OS::chdir (dirname_bak.c_str ()) == -1)
    throw udm_exception (string ("chdir failed: " + dirname_bak));

  if (ACE_OS::chdir (dirname.c_str ()) == -1)
    throw udm_exception (string ("chdir failed: " + dirname));

  ACE_Dirent dir (DIR_DOT);

  for (ACE_DIRENT *directory; (directory = dir.read ()) != 0;)
    {
      if (ACE_OS::strcmp (directory->d_name, DIR_DOT) == 0
          || ACE_OS::strcmp (directory->d_name, DIR_DOT_DOT) == 0)
        continue;

      ACE_stat stat_buf;
      if (ACE_OS::lstat (directory->d_name, &stat_buf) == -1)
        throw udm_exception (string ("lstat failed: ") + string (directory->d_name));

      std::string temp = dirname;
      temp += "/";
      temp += directory->d_name;
      switch (stat_buf.st_mode & S_IFMT)
        {
        case S_IFREG: // Either a regular file or an executable.
          add_files(temp);
          break;

        case S_IFDIR:
          add_dirs(temp + "/");
          get_filenames(temp, dirname_bak);
          if (ACE_OS::chdir (ACE_TEXT ("..")) == -1)
            throw udm_exception (string ("chdir failed: " + dirname));
          break;

        default:
          break;
        }
    }
}

void ZIP_create::add_dirs(const std::string dirname)
{
  std::vector<std::string>::iterator pos;
  pos = find (exist_files_.begin(), exist_files_.end(), dirname);
  if (pos == exist_files_.end())
    dirs_.push_back(dirname);
}

void ZIP_create::add_files(const std::string filename)
{
  std::vector<std::string>::iterator pos;
  pos = find (exist_files_.begin(), exist_files_.end(), filename);
  if (pos == exist_files_.end())
    files_.push_back(filename);
}

void ZIP_create::get_exist_files_in_zip(const std::string filename, const std::string dir)
{
  unzFile uf=0;
  uf = unzOpen (filename.c_str ());
  if (uf==0)
    throw udm_exception
      (string ("There is some problem with zipFile using unzOpen: " + filename));

  uLong i;
  unz_global_info gi;
  int err;
  err = unzGetGlobalInfo (uf,&gi);
  if (err != UNZ_OK)
    throw udm_exception
      (string ("There is some problem with zipFile using unzGetGlobalInfo: " + filename));

  for (i=0;i<gi.number_entry;i++)
    {
      char filename_inzip[256];
      unz_file_info file_info;
      err = unzGetCurrentFileInfo(uf,&file_info,filename_inzip,sizeof(filename_inzip),NULL,0,NULL,0);
      if (err!=UNZ_OK)
        throw udm_exception
          (string ("There is some problem with zipFile using unzGetCurrentFileInfo: " + filename));

      exist_files_.push_back(dir + "/" + filename_inzip);

      if ((i+1)<gi.number_entry)
        {
          err = unzGoToNextFile(uf);
          if (err!=UNZ_OK)
            throw udm_exception
              (string ("There is some problem with zipFile using unzGoToNextFile: " + filename));
        }
    }

  unzClose(uf);
}

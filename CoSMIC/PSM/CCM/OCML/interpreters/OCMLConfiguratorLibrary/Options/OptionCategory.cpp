#include "OptionCategory.hpp"

OptionCategory::OptionCategory(const char* name, const char* description)
  : DescribedItem(name, description)
{
}

OptionCategory::~OptionCategory()
{
  for (category_iterator c_iter = categories_.begin();
       c_iter != categories_.end(); ++c_iter)
    delete *c_iter;

  for (option_iterator o_iter = options_.begin();
       o_iter != options_.end(); ++o_iter)
    delete *o_iter;
}

/// @see DescribedItem::type_string
const char*
OptionCategory::type_string() const
{
  return "OptionCategory";
}

void
OptionCategory::add_category(OptionCategory* category)
{
  categories_.push_back(category);
}

/*
 * STL begin & end markers.
 */

OptionCategory::category_iterator
OptionCategory::begin_categories()
{
  return categories_.begin();
}

OptionCategory::category_iterator
OptionCategory::end_categories()
{
  return categories_.end();
}

OptionCategory::option_iterator
OptionCategory::begin_options()
{
  return options_.begin();
}

OptionCategory::option_iterator
OptionCategory::end_options()
{
  return options_.end();
}

/*
 * STL begin & end markers. - const versions -
 */

OptionCategory::const_category_iterator
OptionCategory::begin_categories() const
{
  return categories_.begin();
}

OptionCategory::const_category_iterator
OptionCategory::end_categories() const
{
  return categories_.end();
}

OptionCategory::const_option_iterator
OptionCategory::begin_options() const
{
  return options_.begin();
}

OptionCategory::const_option_iterator
OptionCategory::end_options() const
{
  return options_.end();
}

void
OptionCategory::add_option(Option* option)
{
  options_.push_back(option);
}

OptionCategory*
OptionCategory::category(const char* name)
{
  for (category_iterator iter = categories_.begin();
       iter != categories_.end(); ++iter)
    {
      if ((*iter)->name() == std::string(name))
        return *iter;
    }

  return NULL;
}

Option*
OptionCategory::option(const char* name)
{
  for (option_iterator iter = options_.begin();
       iter != options_.end(); ++iter)
    {
      if ((*iter)->name() == std::string(name))
        return *iter;
    }

  return NULL;
}

/**
 * Traverses the contained options and categories, calls the write methods,
 * inserts the returning nodes to the current node as children.
 * 
 * @see DescribedItem::write.
 */
xercesc::DOMElement*
OptionCategory::write(xercesc::DOMDocument* doc) const
{
  if (!items_assigned())
    return NULL;

  xercesc::DOMElement* element = DescribedItem::write(doc);

  // Traverse the contained categories and call write methods.
  // 
  for (const_category_iterator c_iter = begin_categories();
       c_iter != end_categories(); ++c_iter)
    {
      xercesc::DOMElement* child = (*c_iter)->write(doc);
      // Append as child if the return value is not NULL.
      if (child)
        element->appendChild(child);
    }

  // Traverse the contained options and call write methods.
  for (const_option_iterator o_iter = begin_options();
       o_iter != end_options(); ++o_iter)
    {
      xercesc::DOMElement* child = (*o_iter)->write(doc);
      // Append as child if the return value is not NULL.
      if (child)
        element->appendChild(child);
    }
  return element;
}

bool
OptionCategory::items_assigned() const
{
  for (const_option_iterator c_iter = begin_options();
       c_iter != end_options(); ++c_iter)
    if ((*c_iter)->assigned())
      return true;

  for (const_category_iterator o_iter = begin_categories();
       o_iter != end_categories(); ++o_iter)
    if ((*o_iter)->items_assigned())
      return true;

  return false;
}

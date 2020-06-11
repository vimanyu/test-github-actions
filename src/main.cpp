#include <iostream>
#include "tinyxml.h"
#include <tinyxml_export.h>


int main()
{
  TiXmlDocument doc("/tmp/onesphere.xml");
  std::cout << "Yes! Successfully ran EVERYTHING!" << std::endl;
}

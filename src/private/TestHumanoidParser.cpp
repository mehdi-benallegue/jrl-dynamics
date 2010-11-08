/*
 * Copyright 2010,
 *
 * Olivier Stasse,
 *
 *
 * JRL/LAAS, CNRS/AIST
 *
 * This file is part of dynamicsJRLJapan.
 * dynamicsJRLJapan is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * dynamicsJRLJapan is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Lesser Public License for more details.
 * You should have received a copy of the GNU Lesser General Public License
 * along with dynamicsJRLJapan.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  Research carried out within the scope of the Associated
 *  International Laboratory: Joint Japanese-French Robotics
 *  Laboratory (JRL)
 *
 */
#include "HSHumanoidNodeParser.hpp"

namespace dynamicsJRLJapan
{
  namespace HumanoidSpecificitiesData {


    namespace fusion = boost::fusion;
    namespace phoenix = boost::phoenix;
    namespace qi = boost::spirit::qi;
    namespace ascii = boost::spirit::ascii;


    int ReadXMLData5(std::string &aFileName,
		     HandNode &ast)
    {
      std::ifstream in((char *)aFileName.c_str(), std::ios_base::in);

      if (!in)
	{
	  std::cerr << "Error: Could not open input file: "
		    << aFileName << std::endl;
	  return 1;
	}

      std::string storage; // We will read the contents here.
      in.unsetf(std::ios::skipws); // No white space skipping!
      std::copy(
		std::istream_iterator<char>(in),
		std::istream_iterator<char>(),
		std::back_inserter(storage));


      struct HandNode_parser<std::string::const_iterator>
	hsxml; // Our grammar


      using boost::spirit::ascii::space;
      std::string::const_iterator iter = storage.begin();
      std::string::const_iterator end = storage.end();

      // this will print something like: boost::fusion::vector2<int, double>
      display_attribute_of_parser(hsxml);

      bool r = phrase_parse(iter, end, hsxml, space, ast);

      if (r && iter == end)
	{
	  std::cout << "-------------------------\n";
	  std::cout << "Parsing succeeded\n";
	  std::cout << "-------------------------\n";
	  return 0;
	}
      else
	{
	  std::string::const_iterator some = iter+30;
	  std::string context(iter, (some>end)?end:some);
	  std::cout << "-------------------------\n";
	  std::cout << "Parsing failed\n";
	  std::cout << "stopped at: \": " << context << "...\"\n";
	  std::cout << "-------------------------\n";
	  return 1;
	}
    }


    int ReadXMLData3(std::string &aFileName,
		     HumanoidNode &ast)
    {
      std::ifstream in((char *)aFileName.c_str(), std::ios_base::in);

      if (!in)
	{
	  std::cerr << "Error: Could not open input file: "
		    << aFileName << std::endl;
	  return 1;
	}

      std::string storage; // We will read the contents here.
      in.unsetf(std::ios::skipws); // No white space skipping!
      std::copy(
		std::istream_iterator<char>(in),
		std::istream_iterator<char>(),
		std::back_inserter(storage));


      struct HumanoidNode_parser<std::string::const_iterator>
	hsxml; // Our grammar


      using boost::spirit::ascii::space;
      std::string::const_iterator iter = storage.begin();
      std::string::const_iterator end = storage.end();

      // this will print something like: boost::fusion::vector2<int, double>
      display_attribute_of_parser(hsxml);

      bool r = phrase_parse(iter, end, hsxml, space, ast);

      if (r && iter == end)
	{
	  std::cout << "-------------------------\n";
	  std::cout << "Parsing succeeded\n";
	  std::cout << "-------------------------\n";
	  return 0;
	}
      else
	{
	  std::string::const_iterator some = iter+30;
	  std::string context(iter, (some>end)?end:some);
	  std::cout << "-------------------------\n";
	  std::cout << "Parsing failed\n";
	  std::cout << "stopped at: \": " << context << "...\"\n";
	  std::cout << "-------------------------\n";
	  return 1;
	}
    }

    int ReadXMLData4(std::string &aFileName,
		     HumanoidNode &ast)
    {
      std::ifstream in((char *)aFileName.c_str(), std::ios_base::in);

      if (!in)
	{
	  std::cerr << "Error: Could not open input file: "
		    << aFileName << std::endl;
	  return 1;
	}

      std::string storage; // We will read the contents here.
      in.unsetf(std::ios::skipws); // No white space skipping!
      std::copy(
		std::istream_iterator<char>(in),
		std::istream_iterator<char>(),
		std::back_inserter(storage));


      struct IHumanoidNode_parser<std::string::const_iterator>
	asc; // Our grammar


      using boost::spirit::ascii::space;
      std::string::const_iterator iter = storage.begin();
      std::string::const_iterator end = storage.end();

      // this will print something like: boost::fusion::vector2<int, double>
      display_attribute_of_parser(asc);

      bool r = phrase_parse(iter, end, asc, space, ast);

      if (r && iter == end)
	{
	  std::cout << "-------------------------\n";
	  std::cout << "Parsing succeeded\n";
	  std::cout << "-------------------------\n";
	  return 0;
	}
      else
	{
	  std::string::const_iterator some = iter+30;
	  std::string context(iter, (some>end)?end:some);
	  std::cout << "-------------------------\n";
	  std::cout << "Parsing failed\n";
	  std::cout << "stopped at: \": " << context << "...\"\n";
	  std::cout << "-------------------------\n";
	  return 1;
	}
    }

  };
};

int main()
{
  namespace dhs=dynamicsJRLJapan::HumanoidSpecificitiesData;
  std::string aFileName("test.xml");
  dhs::HumanoidNode asc;
  dhs::ReadXMLData4(aFileName,asc);
  std::cout <<asc <<std::endl;

  std::string aFileName3("test2.xml");
  dhs::HandNode a2hn;
  dhs::ReadXMLData5(aFileName3,a2hn);
  std::cout <<a2hn <<std::endl;

  std::string aFileName2("/home/stasse/devel/openrobots/share/hrp2_14/HRP2Specificities.xml");
  dhs::HumanoidNode ahn;
  dhs::ReadXMLData3(aFileName,ahn);
  std::cout <<ahn <<std::endl;
}

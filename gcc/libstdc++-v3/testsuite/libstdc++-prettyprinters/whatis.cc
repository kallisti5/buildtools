// { dg-do run }
// { dg-options "-g -O0 -std=gnu++11" }

// Copyright (C) 2011-2013 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING3.  If not see
// <http://www.gnu.org/licenses/>.

#include <string>
#include <iostream>
#include <regex>

template<class T>
void
placeholder(const T *s)
{
  std::cout << (void *) s;
}

template<class T>
struct holder
{
  T *f;
};

typedef std::basic_string<unsigned char> ustring;

// This test is written in a somewhat funny way.
// Each type under test is used twice: first, to form a pointer type,
// and second, as a template parameter.  This is done to work around
// apparent GCC oddities.  The pointer type is needed to ensure that
// the typedef in question ends up in the debuginfo; while the
// template type is used to ensure that a typedef-less variant is
// presented to gdb.

std::string *string_ptr;
holder<std::string> string_holder;
// { dg-final { whatis-test string_holder "holder<std::string>" } }
std::ios *ios_ptr;
holder<std::ios> ios_holder;
// { dg-final { whatis-test ios_holder "holder<std::ios>" } }
std::streambuf *streambuf_ptr;
holder<std::streambuf> streambuf_holder;
// { dg-final { whatis-test streambuf_holder "holder<std::streambuf>" } }
std::istream *istream_ptr;
holder<std::istream> istream_holder;
// { dg-final { whatis-test istream_holder "holder<std::istream>" } }
std::ostream *ostream_ptr;
holder<std::ostream> ostream_holder;
// { dg-final { whatis-test ostream_holder "holder<std::ostream>" } }
std::iostream *iostream_ptr;
holder<std::iostream> iostream_holder;
// { dg-final { whatis-test iostream_holder "holder<std::iostream>" } }
std::stringbuf *stringbuf_ptr;
holder<std::stringbuf> stringbuf_holder;
// { dg-final { whatis-test stringbuf_holder "holder<std::stringbuf>" } }
std::istringstream *istringstream_ptr;
holder<std::istringstream> istringstream_holder;
// { dg-final { whatis-test istringstream_holder "holder<std::istringstream>" } }
std::ostringstream *ostringstream_ptr;
holder<std::ostringstream> ostringstream_holder;
// { dg-final { whatis-test ostringstream_holder "holder<std::ostringstream>" } }
std::stringstream *stringstream_ptr;
holder<std::stringstream> stringstream_holder;
// { dg-final { whatis-test stringstream_holder "holder<std::stringstream>" } }
std::filebuf *filebuf_ptr;
holder<std::filebuf> filebuf_holder;
// { dg-final { whatis-test filebuf_holder "holder<std::filebuf>" } }
std::ifstream *ifstream_ptr;
holder<std::ifstream> ifstream_holder;
// { dg-final { whatis-test ifstream_holder "holder<std::ifstream>" } }
std::ofstream *ofstream_ptr;
holder<std::ofstream> ofstream_holder;
// { dg-final { whatis-test ofstream_holder "holder<std::ofstream>" } }
std::fstream *fstream_ptr;
holder<std::fstream> fstream_holder;
// { dg-final { whatis-test fstream_holder "holder<std::fstream>" } }
std::streampos *streampos_ptr;
holder<std::streampos> streampos_holder;
// { dg-final { whatis-test streampos_holder "holder<std::streampos>" } }
std::regex *regex_ptr;
holder<std::regex> regex_holder;
// { dg-final { whatis-test regex_holder "holder<std::regex>" } }
std::csub_match *csub_match_ptr;
holder<std::csub_match> csub_match_holder;
// { dg-final { whatis-test csub_match_holder "holder<std::csub_match>" } }
std::ssub_match *ssub_match_ptr;
holder<std::ssub_match> ssub_match_holder;
// { dg-final { whatis-test ssub_match_holder "holder<std::ssub_match>" } }
std::cmatch *cmatch_ptr;
holder<std::cmatch> cmatch_holder;
// { dg-final { whatis-test cmatch_holder "holder<std::cmatch>" } }
std::smatch *smatch_ptr;
holder<std::smatch> smatch_holder;
// { dg-final { whatis-test smatch_holder "holder<std::smatch>" } }
std::cregex_iterator *cregex_iterator_ptr;
holder<std::cregex_iterator> cregex_iterator_holder;
// { dg-final { whatis-test cregex_iterator_holder "holder<std::cregex_iterator>" } }
std::sregex_iterator *sregex_iterator_ptr;
holder<std::sregex_iterator> sregex_iterator_holder;
// { dg-final { whatis-test sregex_iterator_holder "holder<std::sregex_iterator>" } }
std::cregex_token_iterator *cregex_token_iterator_ptr;
holder<std::cregex_token_iterator> cregex_token_iterator_holder;
// { dg-final { whatis-test cregex_token_iterator_holder "holder<std::cregex_token_iterator>" } }
std::sregex_token_iterator *sregex_token_iterator_ptr;
holder<std::sregex_token_iterator> sregex_token_iterator_holder;
// { dg-final { whatis-test sregex_token_iterator_holder "holder<std::sregex_token_iterator>" } }
std::u16string *u16string_ptr;
holder<std::u16string> u16string_holder;
// { dg-final { whatis-test u16string_holder "holder<std::u16string>" } }
std::u32string *u32string_ptr;
holder<std::u32string> u32string_holder;
// { dg-final { whatis-test u32string_holder "holder<std::u32string>" } }
std::minstd_rand0 *minstd_rand0_ptr;
holder<std::minstd_rand0> minstd_rand0_holder;
// { dg-final { whatis-test minstd_rand0_holder "holder<std::minstd_rand0>" } }
std::minstd_rand *minstd_rand_ptr;
holder<std::minstd_rand> minstd_rand_holder;
// { dg-final { whatis-test minstd_rand_holder "holder<std::minstd_rand>" } }
std::mt19937 *mt19937_ptr;
holder<std::mt19937> mt19937_holder;
// { dg-final { whatis-test mt19937_holder "holder<std::mt19937>" } }
std::mt19937_64 *mt19937_64_ptr;
holder<std::mt19937_64> mt19937_64_holder;
// { dg-final { whatis-test mt19937_64_holder "holder<std::mt19937_64>" } }
std::ranlux24_base *ranlux24_base_ptr;
holder<std::ranlux24_base> ranlux24_base_holder;
// { dg-final { whatis-test ranlux24_base_holder "holder<std::ranlux24_base>" } }
std::ranlux48_base *ranlux48_base_ptr;
holder<std::ranlux48_base> ranlux48_base_holder;
// { dg-final { whatis-test ranlux48_base_holder "holder<std::ranlux48_base>" } }
std::ranlux24 *ranlux24_ptr;
holder<std::ranlux24> ranlux24_holder;
// { dg-final { whatis-test ranlux24_holder "holder<std::ranlux24>" } }
std::ranlux48 *ranlux48_ptr;
holder<std::ranlux48> ranlux48_holder;
// { dg-final { whatis-test ranlux48_holder "holder<std::ranlux48>" } }
std::knuth_b *knuth_b_ptr;
holder<std::knuth_b> knuth_b_holder;
// { dg-final { whatis-test knuth_b_holder "holder<std::knuth_b>" } }

ustring *ustring_ptr;
holder<ustring> ustring_holder;
// { dg-final { whatis-test ustring_holder "holder<std::basic_string<unsigned char, std::char_traits<unsigned char>, std::allocator<unsigned char> > >" } }

std::basic_string<signed char> *sstring_ptr;
holder< std::basic_string<signed char> > sstring_holder;
// { dg-final { whatis-test sstring_holder "holder<std::basic_string<signed char, std::char_traits<signed char>, std::allocator<signed char> > >" } }

int
main()
{
  placeholder(&ios_ptr);		// Mark SPOT
  placeholder(&ios_holder);
  placeholder(&string_ptr);
  placeholder(&string_holder);
  placeholder(&streambuf_ptr);
  placeholder(&streambuf_holder);
  placeholder(&istream_ptr);
  placeholder(&istream_holder);
  placeholder(&ostream_ptr);
  placeholder(&ostream_holder);
  placeholder(&iostream_ptr);
  placeholder(&iostream_holder);
  placeholder(&stringbuf_ptr);
  placeholder(&stringbuf_holder);
  placeholder(&istringstream_ptr);
  placeholder(&istringstream_holder);
  placeholder(&ostringstream_ptr);
  placeholder(&ostringstream_holder);
  placeholder(&stringstream_ptr);
  placeholder(&stringstream_holder);
  placeholder(&filebuf_ptr);
  placeholder(&filebuf_holder);
  placeholder(&ifstream_ptr);
  placeholder(&ifstream_holder);
  placeholder(&ofstream_ptr);
  placeholder(&ofstream_holder);
  placeholder(&fstream_ptr);
  placeholder(&fstream_holder);
  placeholder(&streampos_ptr);
  placeholder(&streampos_holder);
  placeholder(&regex_ptr);
  placeholder(&regex_holder);
  placeholder(&csub_match_ptr);
  placeholder(&csub_match_holder);
  placeholder(&ssub_match_ptr);
  placeholder(&ssub_match_holder);
  placeholder(&cmatch_ptr);
  placeholder(&cmatch_holder);
  placeholder(&smatch_ptr);
  placeholder(&smatch_holder);
  placeholder(&cregex_iterator_ptr);
  placeholder(&cregex_iterator_holder);
  placeholder(&sregex_iterator_ptr);
  placeholder(&sregex_iterator_holder);
  placeholder(&cregex_token_iterator_ptr);
  placeholder(&cregex_token_iterator_holder);
  placeholder(&sregex_token_iterator_ptr);
  placeholder(&sregex_token_iterator_holder);
  placeholder(&u16string_ptr);
  placeholder(&u16string_holder);
  placeholder(&u32string_ptr);
  placeholder(&u32string_holder);
  placeholder(&minstd_rand0_ptr);
  placeholder(&minstd_rand0_holder);
  placeholder(&minstd_rand_ptr);
  placeholder(&minstd_rand_holder);
  placeholder(&mt19937_ptr);
  placeholder(&mt19937_holder);
  placeholder(&mt19937_64_ptr);
  placeholder(&mt19937_64_holder);
  placeholder(&ranlux24_base_ptr);
  placeholder(&ranlux24_base_holder);
  placeholder(&ranlux48_base_ptr);
  placeholder(&ranlux48_base_holder);
  placeholder(&ranlux24_ptr);
  placeholder(&ranlux24_holder);
  placeholder(&ranlux48_ptr);
  placeholder(&ranlux48_holder);
  placeholder(&knuth_b_ptr);
  placeholder(&knuth_b_holder);
  placeholder(&ustring_ptr);
  placeholder(&ustring_holder);
  placeholder(&sstring_ptr);
  placeholder(&sstring_holder);

  return 0;
}

// { dg-final { gdb-test SPOT } }
#include <string>
#include <Windows.h>
#include <iostream>
#ifndef ROT13_H
#define ROT13_H

namespace rot13 {
	template<typename Input, typename Output, std::enable_if < std::is_same<Input, std::string>::value&& std::is_same<Output, std::string>::value, int>::type = 0>
	Output rot13_encryption( const Input& type ) {
		Output output = "";
		for( auto c : type ) {
			if( isalpha( c ) ) {
				if( isupper( c ) ) {
					output += static_cast< char >( 'A' + ( c - 'A' + 13 ) % 26 ); /* Every Letter in the Alphabet is mapped 13 Letters to the right which means that you can decrypt it by going 13 to the left ( - ). We than % 26 because the rot13 encryption uses 26 Letters in the alphabet  */ 
				}
				else {
					output += static_cast< char >( 'a' + ( c - 'a' + 13 ) % 26 ); 
				}
			}
			else {
				output += c; 
			}
		}
		return output; 
	}
}

#endif // !ROT13_H

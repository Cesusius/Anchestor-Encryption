#include <string>
#include <string_view>

#ifndef ATBASCH_H 
#define ATBASCH_H
namespace atbasch {
	template<typename InputType,
			typename OutputType,
			typename = std::enable_if_t<std::is_integral_v<InputType> || std::is_same_v<InputType, std::string>>>
		OutputType atbasch_encryption( const InputType& type ) {
			OutputType output = "";
			for ( auto c: type ) {
				if( isalpha( c ) ) {
					if( isupper( c ) ) {
						output += static_cast< char >( 'Z' - ( c - 'A' ) );
					}
					else {
						output += static_cast< char >( 'z' - ( c - 'a' ) );
					}
				}
				else {
					output += c;
				}

			}
			return output;
	}				
}

#endif // !Atbasch 

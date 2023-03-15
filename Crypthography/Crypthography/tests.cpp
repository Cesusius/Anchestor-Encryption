#include <Windows.h>
#include <iostream>

#include "Atbasch.h"
#include "ROT13.h"
auto main( ) -> void {

    //Decryption Testing 

    const char* abtasch_message = "Abtasch";
    const char* rot13_message = "Rot13";
    std::string abtasch_input( abtasch_message );
    std::string rot13_input( rot13_message );
    std::string abtasch_encrypted = atbasch::atbasch_encryption<decltype( abtasch_input ), std::string>( abtasch_input );
    std::string rot13_encrypted = ( rot13::rot13_encryption<decltype( rot13_input ), std::string>( rot13_input ) ); 
    std::cout << "Atbasch Encrypted --> " << abtasch_encrypted << std::endl;
    std::cout << "Rot13 Encrypted --> " << rot13_encrypted << std::endl;
    std::cin.get( ); 
}
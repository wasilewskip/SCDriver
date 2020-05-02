#include "SteamInputPacket.h"
#include <iostream>
#include <stdlib.h>

SteamInputPacket::SteamInputPacket(uint8_t* data)
{
    buttons = std::bitset<24>(data[8] << 16 | data[9] << 8| data[10]);

    leftTrigger = data[11];
    rightTrigger = data[12];

    lpadX = ( data[17] << 8 | data[16] );
    lpadY = ( data[19] << 8 | data[18] );
    rpadX = ( data[21] << 8 | data[20] );
    rpadY = ( data[23] << 8 | data[22] );

    // print();
}

void SteamInputPacket::print()  
{
        system("cls");
        std::cout << "Printing packet\n";
        std::cout << "Buttons: " << buttons << "\n";
        std::cout << "leftTrigger: " << leftTrigger << "\n";
        std::cout << "rightTrigger: " << rightTrigger << "\n";
        std::cout << "lpadX: " << lpadX << "\n";
        std::cout << "lpadY: " << lpadY << "\n";
        std::cout << "rpadX: " << rpadX << "\n";
        std::cout << "rpadY: " << rpadY << "\n";
 
 
}
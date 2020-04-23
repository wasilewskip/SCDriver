#include <memory>
#include "Connection/Usb.h"
#include "Connection/DongleConnection.h"
#include "SteamController.h"
#include "Buttons/ButtonCollection.h"

int main(int argc, const char** argv){

  auto usbPtr = std::make_unique<Usb>();
  std::unique_ptr<IConnection> connectionPtr = std::make_unique<DongleConnection>(std::move(usbPtr));
  auto buttons = std::make_unique<ButtonCollection>();
  auto steamControllerPtr = std::make_unique<SteamController>(std::move(connectionPtr), std::move(buttons));

  steamControllerPtr->run();

  return 0;
}
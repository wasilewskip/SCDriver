#include <memory>
#include "Connection/Usb.h"
#include "Connection/DongleConnection.h"
#include "SteamController.h"
#include "Buttons/ButtonCollection.h"
#include "Devices/IDeviceFactory.h"
#include "Devices/WindowsDeviceFactory.h"

int main(int argc, const char** argv){

  auto usbPtr = std::make_unique<Usb>();
  std::unique_ptr<IConnection> connectionPtr = std::make_unique<DongleConnection>(std::move(usbPtr));
  auto buttons = std::make_unique<ButtonCollection>();
  std::unique_ptr<IDeviceFactory> deviceFactory = std::make_unique<WindowsDeviceFactory>();
  std::unique_ptr<ActionListener> actionListener = std::make_unique<ActionListener>(std::move(deviceFactory));
  auto steamControllerPtr = std::make_unique<SteamController>(std::move(connectionPtr), std::move(buttons), std::move(actionListener));

  steamControllerPtr->run();

  return 0;
}
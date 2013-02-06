#include <iostream>
#include <iomanip>
#include <usbpp.h>

#define VENDOR_FUTURETECH 0x0403

using namespace std;

int main(void)
{
       USB::Busses buslist;
       USB::Device *device;
       list<USB::Device *> devsFound;
       list<USB::Device *>::const_iterator iter;

       cout << "idVendor/idProduct/bcdDevice" << endl;

       USB::DeviceIDList devList;

       devList.push_back(USB::DeviceID(VENDOR_FUTURETECH, 0x6001)); // dlpio8

       devsFound = buslist.match(devList);

       for (iter = devsFound.begin(); iter != devsFound.end(); iter++) {
              device = *iter;

              cout << hex << setw(4) << setfill('0')
                      << device->idVendor() << "  /  "
                      << hex << setw(4) << setfill('0')
                      << device->idProduct() << "  /  "
                      << hex << setw(4) << setfill('0')
                      << device->idRevision() << "       "
                      << endl;
       }

       return 0;
}

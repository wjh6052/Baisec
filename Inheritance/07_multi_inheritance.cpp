// 07_multi_inheritance.cpp

// ����: ���� ����� ������ ����, ���̾Ƹ�� ��� ���� ����

/*
   Multi Inheritance - ���� ���
   - �� Ŭ������ �� �� �̻��� Ŭ������ ��ӹ޴� ��
   - ���� ����� ���� ����� �ƴϱ� ������ �ٸ� ������
   ������� �ʴ� ��쵵 �ִ�.
*/

#include<iostream>
using namespace std;

class USBDevice
{

public:
    USBDevice() = default;
    explicit USBDevice(int id) : id(id) {}

    auto GetID() const { return id; }
    void PlugAndPlay() {}

private:
    int id;
};

class NetworkDevice
{
public:
    NetworkDevice() = default;
    NetworkDevice(int id) : id(id) {}

    auto GetID() const { return id; }
    void Networking() {}

private:
    int id;
};

// �� �� �̻��� Ŭ������ ��ӹް� ����. -> ���� ���
class USBNetworkDevice : public USBDevice, public NetworkDevice
{
public:
    USBNetworkDevice(int usb_id, int net_id)
        : USBDevice(usb_id)   // ���ϴ� ������ ȣ�� ����� �����Ͽ� ����
        , NetworkDevice(net_id)
    {}

    USBNetworkDevice(int id)
        : USBDevice(id)
        , NetworkDevice(id)
    {}
};

int main()
{
    USBNetworkDevice device(1.10, 2.10);
    device.PlugAndPlay();
    device.Networking();

    // ��� Ŭ������ ��� �Լ��� �ߺ��Ǿ� ��ȣ��
    //device.GetID(); // error = ambiguos

    // �ذ���1 -> �ߺ��� �Լ��̸��� ���� -> ���ŷο�

    // �ذ���2 -> �̸� �����Ͽ� ������� 
    cout << device.USBDevice::GetID() << endl;
    cout << device.NetworkDevice::GetID() << endl;

    return 0;
}
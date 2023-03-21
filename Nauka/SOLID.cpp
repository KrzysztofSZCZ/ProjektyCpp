#include <iostream>
#include <vector>
//struktura łamiąca S

struct Camera{};
struct CloudProvider{};
struct Image{};

struct PhotoUploader{
PhotoUploader(Camera& camera, CloudProvider& cloudProvider);
Image getImage();
Image resizeImage(int x, int y, Image image);
void uploadImage ( Image& image);
// problem jest taki, że jedna klasa nie tylko uploaduje obraz, ale jeszcze go resizuje więc wykonuje za dużo czynności
//dodatkowo ta sama klasa pozwala pokazać ten obraz co może być unzane za kolejne zadanie
};

//sruktura łamiąca O

enum class SensorModel{
    Good,
    Better
};

struct DistanceSensor{
    SensorModel mModel;
DistanceSensor(SensorModel model) : mModel(model) {}

int getDistance(){

    switch (mModel){
        case SensorModel::Good:
        //cos tam zrobi 
        case SensorModel::Better:
        //coś innego zrobi

    }

}

//problem jest taki, żę jeżeli dodamy inny model sensora np Bad to będziemy musieli zmienić meetodę getDistance, bo nie obsługuje tego 
};
//lepiej zrobić interfejs z Sensor model, a kolejne distancesensory powinny być pochodnymi i wtedy można dodawać nwoe po porstu bez zmian


//struktura łamiąca L

struct MeasurementUnit{

    virtual int getOrientation() = 0;
};

struct Gyroscope : public MeasurementUnit{

    int getOrientation() override;
    //zwraca [0,360)

};

struct Accelerometer : public MeasurementUnit{

    int getOrientation() override;
    // zwraca [-180, 180)

};

//problem jest taki, że nie wiemy czy otrzymamy liczbę dodatnią czy ujmeną więc musimy cały czas przejmować się tym, ktorego childa używamy, a to łamie tę zasadę 
//żeby naprawić należy upwenić się że każdy child zachowa się tak samo, a jeśli to niemożliwe to może powinniśmy zmienić hierarchię klasy


//struktura łamiąca I

struct byte{};
struct PinDirection{};

struct Runtime{
    virtual ~Runtime() = default;

    virtual void sendViaI2C(std::vector<byte> byteToSend) = 0;
    virtual std::vector<byte> readViaI2C(int numberOfBitesToRead) = 0;

    virtual void sendViaUART(std::vector<byte> byteToSend) = 0;
    virtual std::vector<byte> readViaUART(int numberOfBitesToRead) = 0;


    virtual void setPinDirection(int p, PinDirection d ) = 0;
    virtual void setPin(int pin) = 0;
    virtual void clearPin(int pin) = 0;

//problemem będzie to że im więcej sposób komunikacji lub funkcjonalności zostanie dodane, tym mniej będzie można go utrzymać 
//używanie takich dużych interfejsów jest niepotrzebne
//dobrym sposobem określenia że zostao naruszone będzie to, zę childy mają metody/ funkcje których nie używają, a są tylko po to żeby interfejs był pełny 
};

//struktura łamiąca D

struct AwsCloud{
    void uploadToS3Bucket(std::string filepath){}

};

struct FIleUploader{
    FIleUploader(AwsCloud& awsCloud);
    void SchduleUpload(std::string filepath);


};

//jak widać file uploader zależy od tego co uploadujemy a żadne z nich nie jest intefejsem
//w teorii uploadera nie powinno obchodzić do jakiego cloud uploadera dodajemy, skoro on tylko planuje kiedy uploadujemy
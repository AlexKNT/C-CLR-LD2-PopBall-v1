#pragma once
using namespace System;
using namespace System::Drawing;
using namespace System::Resources;

ref class Pictures {
private:
    static Bitmap^ LoadBitmap(String^ bitmapName) {
        Reflection::Assembly^ assembly = Reflection::Assembly::GetExecutingAssembly();
        ResourceManager^ resman = gcnew ResourceManager("C-CLR-LD2-PopBall-v1.Pictures", assembly);
        return (Bitmap^)resman->GetObject(bitmapName);
    }
public:
    static Bitmap^ house = LoadBitmap("dom64.png");
    static Bitmap^ pig = LoadBitmap("hru64.png");
    static Bitmap^ grass = LoadBitmap("grass64.png");
    static Bitmap^ bear = LoadBitmap("miha64.png");
    static Bitmap^ tree = LoadBitmap("tree64.png");
    static Bitmap^ bobr = LoadBitmap("bobr64.png");
    static Bitmap^ farmer = LoadBitmap("farm64.png");
};
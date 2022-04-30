#ifndef Glob_hpp
#define Glob_hpp

class Global{
    public:
        static int width;
        static int height;
        static bool isRunning;
        static void setWidth(int w);
        static void setHeight(int h);
        static int getWidth();
        static int getHeight();
};

#endif
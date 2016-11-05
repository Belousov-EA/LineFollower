#ifndef RETURN_ON_LINE_H
#define RETURN_ON_LINE_H

class ReturnOnLine
{
  public:
    inline void setValues(float exc, float dark);
    float getLastExc();
    inline bool lineLosted();
  private:
    int darkCount;
    float lastExc;
};

#endif

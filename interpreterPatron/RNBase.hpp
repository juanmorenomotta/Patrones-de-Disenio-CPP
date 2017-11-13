#include <string.h>

class RNBase
{
  public:
    RNBase(){}

    virtual void interpret(char *input, int &total)
    {
        // for internal use
        int index;
        index = 0;
        if (!strncmp(input, nine(), 2))
        {
            total += 9 * multiplier();
            index += 2;
        }
        else if (!strncmp(input, four(), 2))
        {
            total += 4 * multiplier();
            index += 2;
        }
        else
        {
            if (input[0] == five())
            {
                total += 5 * multiplier();
                index = 1;
            }
            else
              index = 0;
            for (int end = index + 3; index < end; index++)
              if (input[index] == one())
                total += 1 * multiplier();
              else
                break;
        }
        strcpy(input, &(input[index]));
    } // remove leading chars processed
  protected:
    // cannot be pure virtual because client asks for instance
    virtual char one(){}
    virtual char* four(){}
    virtual char five(){}
    virtual char* nine(){}
    virtual int multiplier(){}
};

class Thousand: public RNBase
{
  private:
    char One = 'M';
    char Four[3] = "Mv";
    char Five = 'v';
    char Nine[3] = "Mx";
  public:
    // provide 1-arg ctor to avoid infinite loop in base class ctor
    Thousand(): RNBase(){}
  protected:
    char one();
    char* four();
    char five();
    char* nine();
    int multiplier();
};

class Hundred: public RNBase
{
  private:
    char One = 'C';
    char Four[3] = "CD";
    char Five = 'D';
    char Nine[3] = "CM";
  public:
    Hundred(): RNBase(){}
  protected:
    char one();
    char* four();
    char five();
    char* nine();
    int multiplier();
};

class Ten: public RNBase
{
  private:
    char One = 'X';
    char Four[3] = "XL";
    char Five = 'L';
    char Nine[3] = "XC";
  public:
    Ten(): RNBase(){}
  protected:
    char one();
    char* four();
    char five();
    char* nine();
    int multiplier();
};

class One: public RNBase
{
  private:
    char _One = 'I';
    char Four[3] = "IV";
    char Five = 'V';
    char Nine[3] = "IX";
  public:
    One(): RNBase(){}
  protected:
    char one();
    char* four();
    char five();
    char* nine();
    int multiplier();
};

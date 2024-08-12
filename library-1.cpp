#include <iostream>
#include <iomanip>

using namespace std;

int readInput(string message)
{
  int inputNum;
  cout << message + "\n";
  cin >> inputNum;
  return inputNum;
}

void ReadArray(int arr[100], int &arrLength)
{
  cout << "\nEnter number of elements:\n";
  cin >> arrLength;
  cout << "\nEnter array elements: \n";
  for (int i = 0; i < arrLength; i++)
  {
    cout << "Element [" << i + 1 << "] : ";
    cin >> arr[i];
  }
  cout << endl;
}

void PrintArray(int arr[100], int arrLength)
{
  for (int i = 0; i < arrLength; i++)
    cout << arr[i] << " ";
  cout << "\n";
}

int randomNumber(int From, int To)
{ // Function to generate a random number
  int randNum = rand() % (To - From + 1) + From;
  return randNum;

  // Put the next line in main
  //  srand((unsigned)time(NULL));
}

int findMax(int arr[], int size)
{
  int max = arr[0];
  for (int i = 0; i < size; i++)
  {
    if (arr[i] > max)
    {
      max = arr[i];
    }
  }
  return max;
}

int findMin(int arr[], int size)
{
  int min = arr[0];
  for (int i = 0; i < size; i++)
  {
    if (arr[i] < min)
    {
      min = arr[i];
    }
  }
  return min;
}

int arrSum(int arr[], int size)
{
  int sum = 0;
  for (int i = 0; i < size; i++)
  {
    sum += arr[i];
  }
  return sum;
}

bool isPrime(int num)
{
  if (num == 1)
  {
    return false;
  }
  for (int i = 2; i <= num / 2; ++i)
  {
    if (num % i == 0)
    {
      return false;
    }
  }

  return true;
}
void shuffleArr(int arr[], int size)
{
  for (int i = 0; i < size; ++i)
  {
    int x = randomNumber(0, size - 1),
        y = randomNumber(0, size - 1);
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
  }
}

void fillArrWithRandom(int arr[], int size)
{
  for (int i = 0; i < size; ++i)
  {
    arr[i] = randomNumber(1, 100);
  }
}

void arrReverseCopy(int originArr[], int reverseArr[], int size)
{
  for (int i = 0; i < size; ++i)
  {
    reverseArr[size - 1 - i] = originArr[i];
  }
}

string generateWord(int length)
{
  string word = "";
  for (int i = 0; i < length; i++)
  {
    word += char(randomNumber(65, 90));
  }
  return word;
}

string generateKey(int length)
{
  string key = "";
  for (int i = 0; i < length; ++i)
  {
    key += generateWord(4);
    if (i != length - 1)
    {
      key += "-";
    }
  }
  return key;
}

void fillArrWithKeys(string arr[], int size)
{
  for (int i = 0; i < size; ++i)
  {
    arr[i] = generateKey(4);
  }
}

int indexOf(int arr[], int size, int value)
{
  for (int i = 0; i < size; ++i)
  {
    if (arr[i] == value)
    {
      return i;
    }
  }

  return -1;
}

void addElementToArr(int arr[], int &size, int element)
{
  arr[size] = element;
  size++;
}

void DynamicRead(int arr[], int &size)
{
  int choice;
  int num;
  cout << "Please Enter a number: ";
  cin >> num;
  addElementToArr(arr, size, num);

  cout << "Do You Want More? [0], [1]: ";
  cin >> choice;
  switch (choice)
  {
  case 0:
  {
    cout << "Array elements is: ";
    for (int i = 0; i < size; ++i)
    {
      cout << arr[i];
    }
    cout << "\n";
    cout << size << "\n";
    break;
  }
  case 1:
  {
    DynamicRead(arr, size);
    break;
  }
  }
}

bool isPalindrome(int arr[], int size)
{
  for (int i = 0; i <= size / 2; ++i)
  {
    if (arr[i] != arr[size - 1 - i])
    {
      return false;
    }
  }
  return true;
}

int countPostive(int arr[], int size)
{
  int count = 0;
  for (int i = 0; i < size; ++i)
  {
    if (arr[i] > 0)
    {
      count++;
    }
  }
  return count;
}

int abs(int num)
{
  if (num < 0)
  {
    return (num * -1);
  }
  return num;
}

int countNegative(int arr[], int size)
{
  int count = 0;
  for (int i = 0; i < size; ++i)
  {
    if (arr[i] < 0)
    {
      count++;
    }
  }
  return count;
}

void fillMatrixWithOrdered(int matrix[3][3], short rows, short cols)
{
  int val = 1;
  for (int i = 0; i < rows; ++i)
  {

    for (int j = 0; j < rows; ++j)
    {
      matrix[i][j] = val;
      ++val;
    }
  }
}

void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{
  for (short i = 0; i < Rows; i++)
  {
    for (short j = 0; j < Cols; j++)
    {
      arr[i][j] = randomNumber(1, 100);
    }
  }
}

void printMatrix(int arr[3][3], short Rows, short Cols)
{
  for (short i = 0; i < Rows; i++)
  {
    for (short j = 0; j < Cols; j++)
    {
      cout << setw(3) << arr[i][j] << "     ";
    }
    cout << "\n";
  }
}

bool isMatricesTypical(int matrix1[3][3], int matrix2[3][3], short rows, short cols)
{
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      if (matrix1[i][j] != matrix2[i][j])
      {
        return false;
      }
    }
  }
  return true;
}

bool isMatricesEqual(int matrix1[3][3], int matrix2[3][3], short rows, short cols)
{
  int sum1 = 0, sum2 = 0;
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      sum1 += matrix1[i][j];
      sum2 += matrix2[i][j];
    }
  }

  if (sum1 == sum2)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool isIdentityMatrix(int matrix[3][3], int rows, int cols)
{
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      if (j == i)
      {
        if (matrix[i][j] != 1)
        {
          return false;
        }
      }
      else
      {
        if (matrix[i][j] != 0)
        {
          return false;
        }
      }
    }
  }
  return true;
}
bool isScalarMatriox(int matrix[3][3], int rows, int cols)
{
  int scVal = matrix[0][0];
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      if (j == i)
      {
        if (matrix[i][j] != scVal)
        {
          return false;
        }
      }
      else
      {
        if (matrix[i][j] != 0)
        {
          return false;
        }
      }
    }
  }
  return true;
}

short countNumInMatrix(int matrix[3][3], short rows, short cols, int num)
{
  short counter = 0;
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      if (matrix[i][j] == num)
      {
        counter++;
      }
    }
  }
  return counter;
}

bool isSpareMatrix(int matrix[3][3], short rows, short cols)
{
  return (countNumInMatrix(matrix, rows, cols, 0) >= 0.5 * rows * cols);
}

bool isExistInMatrix(int matrix[3][3], short rows, short cols, int num)
{
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      if (matrix[i][j] == num)
      {
        return true;
      }
    }
  }
  return false;
}

int getMaxInMatrix(int matrix[3][3], int rows, int cols)
{
  int max = matrix[0][0];
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      if (matrix[i][j] > max)
      {
        max = matrix[i][j];
      }
    }
  }
  return max;
}

int getMinInMatrix(int matrix[3][3], int rows, int cols)
{
  int min = matrix[0][0];
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      if (matrix[i][j] < min)
      {
        min = matrix[i][j];
      }
    }
  }
  return min;
}

void printMaxAndMinInMatrix(int matrix[3][3], int rows, int cols)
{
  cout << "Min is: " << getMinInMatrix(matrix, rows, cols) << endl;
  cout << "Max is: " << getMaxInMatrix(matrix, rows, cols) << endl;
}

bool isArrPalindrome(int arr[], int size)
{
  for (int i = 0; i <= size / 2; ++i)
  {
    if (arr[i] != arr[size - 1 - i])
    {
      return false;
    }
  }
  return true;
}

bool isMatrixPalindrome(int matrix[3][3], short rows, short cols)
{
  for (int i = 0; i < rows; ++i)
  {
    // for (int j = 0; j < cols; ++j)
    // {
    if (!isArrPalindrome(matrix[i], cols))
    {
      return false;
    }
    // }
  }
  return true;
}

void PrintFebSer(short num, int prev1, int prev2)
{
  int febNum = 0;
  if (num > 0)
  {
    febNum = prev1 + prev2;
    prev2 = prev1;
    prev1 = febNum;
    cout << febNum << "    ";
    PrintFebSer(num - 1, prev1, prev2);
  }
}

void printFebonacciUsingLoop(int num)
{
  int prev1 = 1, prev2 = 0;
  for (int i = 2; i <= num; ++i)
  {
    int febNum = prev1 + prev2;
    cout << febNum << "  ";
    prev2 = prev1;
    prev1 = febNum;
  }
}

string readString()
{
  string s1;
  cout << "Please Enter Your String:\n";
  getline(cin, s1);
  return s1;
}

void printFirstOfEachWord(string sentence)
{
  cout << sentence[0] << "\n";
  for (int i = 0; i < sentence.length(); ++i)
  {
    if (sentence[i] == ' ')
    {
      cout << sentence[i + 1] << "\n";
    }
  }
}

char uppercase(char c)
{
  if (c > 96 && c < 123)
  {
    return (c - 32);
  }
  else
  {
    return c;
  }
}

string makeFirstLetterUppercase(string sentence)
{
  sentence[0] = uppercase(sentence[0]);
  for (int i = 0; i < sentence.length(); ++i)
  {
    if (sentence[i] == ' ')
    {
      sentence[i + 1] = uppercase(sentence[i + 1]);
    }
  }
  return sentence;
}

char lowercase(char c)
{
  if (c > 64 && c < 91)
  {
    return (c + 32);
  }
  else
  {
    return c;
  }
}

string makeFirstLetterLowercase(string sentence)
{
  sentence[0] = lowercase(sentence[0]);
  for (int i = 0; i < sentence.length(); ++i)
  {
    if (sentence[i] == ' ')
    {
      sentence[i + 1] = lowercase(sentence[i + 1]);
    }
  }
  return sentence;
}

string lowercaseEntireString(string sentence)
{
  for (int i = 0; i < sentence.length(); ++i)
  {
    sentence[i] = lowercase(sentence[i]);
  }
  return sentence;
}

string uppercaseEntireString(string sentence)
{
  for (int i = 0; i < sentence.length(); ++i)
  {
    sentence[i] = uppercase(sentence[i]);
  }
  return sentence;
}

char readChar()
{
  char c;
  cout << "Plz Enter Char: ";
  cin >> c;
  return c;
}

char toggleCharCase(char c)
{
  return islower(c) ? toupper(c) : tolower(c);
}

int smallCount(string sentence)
{
  int smallCounter = 0;
  for (int i = 0; i < sentence.length(); ++i)
  {
    if (islower(sentence[i]))
    {
      smallCounter++;
    }
  }
  return smallCounter;
}

int capitalCount(string sentence)
{
  int capitalCounter = 0;
  for (int i = 0; i < sentence.length(); ++i)
  {
    if (isupper(sentence[i]))
    {
      capitalCounter++;
    }
  }
  return capitalCounter;
}

void countThenPrint(string s)
{
  cout << "String Length = " << s.length() << "\n";
  cout << "Capital Letters Count = " << capitalCount(s) << "\n";
  cout << "Small Letters Count = " << smallCount(s) << "\n";
}

int countLetter(string s, char c)
{
  int counter = 0;
  for (int i = 0; i < s.length(); ++i)
  {
    if (s[i] == c)
    {
      ++counter;
    }
  }
  return counter;
}

int countLetterMatchCase(string s, char c, bool matchCase = true)
{
  int counter = 0;
  for (int i = 0; i < s.length(); ++i)
  {
    if (matchCase)
    {
      if (s[i] == c)
      {
        ++counter;
      }
    }
    else
    {
      if (toupper(s[i]) == toupper(c))
      {
        ++counter;
      }
    }
  }
  return counter;
}

bool isVowel(char c)
{
  c = tolower(c);
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
  {
    return true;
  }
  else
  {
    return false;
  }
}

int countVowel(string s)
{
  int counter = 0;
  for (int i = 0; i < s.length(); ++i)
  {
    if (isVowel(s[i]))
    {
      ++counter;
    }
  }
  return counter;
}

void printEachWordOfString(string s)
{
  string space = " ";
  cout << "\n Your String Words Are: \n";
  short pos = 0; // Position
  string word;

  while ((pos = s.find(space)) != std::string::npos)
  {
    word = s.substr(0, pos);
    if (word != "")
    {
      cout << word << endl;
    }
    s.erase(0, pos + space.length());
  }

  if (s != "")
  {
    cout << s << endl;
  }
}

int countWordsInString(string s)
{
  string space = " ";
  short pos = 0; // Position
  string word;

  int counter = 0;
  while ((pos = s.find(space)) != std::string::npos)
  {
    word = s.substr(0, pos);
    if (word != "")
    {
      counter++;
    }
    s.erase(0, pos + space.length());
  }

  if (s != "")
  {
    counter++;
  }
  return counter;
}

vector<string> splitString(string S1, string Delim)
{
  vector<string> vString;
  short pos = 0;
  string sWord; // define a string variable
                // use find() function to get the position of the delimiters
  while ((pos = S1.find(Delim)) != std::string::npos)
  {
    sWord = S1.substr(0, pos);
    // store the word
    if (sWord != "")
    {
      vString.push_back(sWord);
    }
    S1.erase(0, pos + Delim.length());
    /* erase() until positon and move to next word. */
  }
  if (S1 != "")
  {
    vString.push_back(S1); // it adds last word of the string.
  }
  return vString;
}

string trimLeft(string s)
{
  for (int i = 0; i < s.length(); ++i)
  {
    if (s[i] != ' ')
    {
      return s.substr(i, s.length() - 1);
    }
  }
  return s;
}

string trimRight(string s)
{
  for (int i = s.length() - 1; i >= 0; --i)
  {
    if (s[i] != ' ')
    {
      return s.substr(0, i + 1);
    }
  }
  return s;
}

string trim(string s)
{
  return trimRight(trimLeft(s));
}

string joinString(string arr[], int length, string delim)
{
  string sentence;
  for (int i = 0; i < length; ++i)
  {
    sentence += arr[i];
    if (i < (length - 1))
    {
      sentence += delim;
    }
  }

  return sentence;
}

//
string ReplaceWordInString(string S1, string StringToReplace, string sRepalceTo)
{
  short pos = S1.find(StringToReplace);
  while (pos != std::string::npos)
  {
    S1 = S1.replace(pos, StringToReplace.length(), sRepalceTo);
    pos = S1.find(StringToReplace); //
  }
  return S1;
}
//

string joinString(vector<string> vString, string delim)
{
  string sentence;
  for (string &s : vString)
  {
    sentence += s + delim;
  }
  return sentence.substr(0, sentence.length() - delim.length());
}

string reverseString(string str)
{
  vector<string> vString = splitString(str, " ");
  string s;
  for (int i = vString.size() - 1; i >= 0; --i)
  {
    s += vString[i] + " ";
  }
  return s;
}

string removePuncFromString(string s)
{
  string s2 = "";
  for (int i = 0; i < s.length(); ++i)
  {
    if (!ispunct(s[i]))
    {
      s2 += s[i];
    }
  }
  return s2;
}

//? Important

struct stClient
{
  string accNum;
  string pinCode;
  string name;
  string phone;
  float accBalance;
};

string readString(string message)
{
  string s1;
  cout << message;
  getline(cin, s1);
  return s1;
}

int readFloat(string message)
{
  int num;
  cout << message;
  cin >> num;
  return num;
}

string generateLineFromRecord(stClient client, string sep)
{
  string line = client.accNum + sep;
  line += client.pinCode + sep;
  line += client.name + sep;
  line += client.phone + sep;
  line += to_string(client.accBalance);

  return line;
}

stClient readNewClient()
{
  stClient client;
  client.accNum = readString("Plz enter account number: ");
  client.pinCode = readString("plz enter pin Code: ");
  client.name = readString("plz Enter ur name: ");
  client.phone = readString("plz enter ur phone num: ");
  client.accBalance = readFloat("plz enter Account balance($): ");

  return client;
}

stClient convertLineToRecored(string line, string sep)
{
  stClient client;
  vector<string> clientData = splitString(line, sep);

  client.accNum = clientData[0];
  client.pinCode = clientData[1];
  client.name = clientData[2];
  client.phone = clientData[3];
  client.accBalance = stof(clientData[4]);

  return client;
}

void printClientData(stClient client)
{
  cout << "Account Number   : " << client.accNum << "\n";
  cout << "Pin Code         : " << client.pinCode << "\n";
  cout << "Member Name      : " << client.name << "\n";
  cout << "Phone Number     : " << client.phone << "\n";
  cout << "Total Balance    : " << client.accBalance << "\n";
}

//! /////////
int main()
{

  return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
struct SCP {
    int id;
    int objClass;
    string speConProcedures;
    string description;
    string* addendums;
    int numAddendums;
};
SCP* cloneSCP(SCP* original) {
   SCP* clone = new SCP;
   clone->id = original->id;
   clone->objClass = original->objClass;
   clone->speConProcedures = original->speConProcedures;
   clone->description = original->description;
   clone->numAddendums = original->numAddendums;
   clone->addendums = new string[original->numAddendums];
   for (int i = 0 ; i<original->numAddendums;i++){
    clone->addendums[i] = original->addendums[i];
   }
   return clone;
}

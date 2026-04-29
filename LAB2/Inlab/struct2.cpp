string convertToString(SCP obj) {
    string s;
    s += "Item #: SCP-";
    s += (obj.id < 10 ? "00" : (obj.id < 100 ? "0" : ""));
    s += to_string(obj.id) + "\n";
    s += "Object Class: ";
    s += (obj.objClass == 0 ? "Safe" : (obj.objClass == 1 ? "Euclid" : "Keter"));
    s += "\nSpecial Containment Procedures: " + obj.speConProcedures + "\n";
    s += "Description: " + obj.description + "\n";
    for (int i = 0; i < obj.numAddendums; i++) {
        s += obj.addendums[i] + "\n";
    }
    return s;
}
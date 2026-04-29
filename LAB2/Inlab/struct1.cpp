SCP createSCP(int id, int objClass, string speConProcedures, string description, string* addendums, int numAddendums) {
    SCP newSCP;
    newSCP.id = id;
    newSCP.objClass = objClass;
    newSCP.speConProcedures = speConProcedures;
    newSCP.description = description;
    newSCP.addendums = addendums;
    newSCP.numAddendums = numAddendums;
    return newSCP;
    
}
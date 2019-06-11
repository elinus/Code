#include <iostream>
#include <string>
#include <sqlite3.h>

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    int i;
    for(i = 0; i<argc; i++) {
        std::cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << "\n";
    }
    std::cout << "\n";
    return 0;
}

int main (int argc, char const *argv[])
{
    sqlite3 *db;
    char *zErrMsg = 0;
    const char* data = "Callback function called";

    /* Open database */
    int res = sqlite3_open("test.db", &db);
    if(res) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return 0;
    } else {
        std::cout << "Opened database successfully!\n";
    }

    /* Create SQL statement */
    std::string sql = "CREATE TABLE COMPANY("  \
                       "ID INT PRIMARY KEY     NOT NULL," \
                       "NAME           TEXT    NOT NULL," \
                       "AGE            INT     NOT NULL," \
                       "ADDRESS        CHAR(50)," \
                       "SALARY         REAL );";

    /* Execute SQL statement */
    res = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    if (res != SQLITE_OK){
        std::cerr << "SQL error: " << zErrMsg << "\n";
        sqlite3_free(zErrMsg);
    } else {
        std::cout << "Table created successfully!\n";
    }

    /* Create SQL statement */
    sql = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
           "VALUES (1, 'Paul', 32, 'California', 20000.00 ); " \
           "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
           "VALUES (2, 'Allen', 25, 'Texas', 15000.00 ); "     \
           "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
           "VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );" \
           "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
           "VALUES (4, 'Mark', 25, 'Rich-Mond ', 65000.00 );";

    /* Execute SQL statement */
    res = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    if(res != SQLITE_OK){
        std::cerr << "SQL error: " << zErrMsg << "\n";
        sqlite3_free(zErrMsg);
    } else {
        std::cout << "Records created successfully!\n";
    }

    /* Create SQL statement */
    sql = "SELECT * from COMPANY";
    /* Execute SQL statement */
    res = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &zErrMsg);

    if(res != SQLITE_OK) {
        std::cout << "SQL error: " << zErrMsg << "\n";
        sqlite3_free(zErrMsg);
    } else {
        std::cout << "Operation done successfully!\n";
    }

    /* Create merged SQL statement */
    sql = "UPDATE COMPANY set SALARY = 25000.00 where ID=1; " \
           "SELECT * from COMPANY";

    /* Execute SQL statement */
    res = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &zErrMsg);

    if (res != SQLITE_OK) {
        std::cerr << "SQL error: " << zErrMsg << "\n";
        sqlite3_free(zErrMsg);
    } else {
        std::cout << "Operation done successfully!\n";
    }
    
    /* Close database */
    sqlite3_close(db);

    return 0;
}


#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <sqlite3.h>

std::vector<std::vector<std::string> > query(sqlite3 *database, std::string query){
    sqlite3_stmt *statement;
    std::vector<std::vector<std::string> > results;
    if(sqlite3_prepare_v2(database, query.c_str(), -1, &statement, 0) == SQLITE_OK) {
        int cols = sqlite3_column_count(statement);
        std::vector<std::string> col_values;
        for(int col = 0; col < cols; col++) {
            col_values.push_back((char*)sqlite3_column_name(statement, col));
        }
        results.push_back(col_values);
        int result = 0;
        while(true) {
            result = sqlite3_step(statement);
            if(result == SQLITE_ROW) {
                std::vector<std::string> values;
                for(int col = 0; col < cols; col++) {
                    values.push_back((char*)sqlite3_column_text(statement, col));
                }
                results.push_back(values);
            } else {
                break;  
            }
        }
        sqlite3_finalize(statement);
    }

    std::string error = sqlite3_errmsg(database);
    if(error != "not an error") std::cout << query << " " << error << std::endl;
    return results; 
}

void print_db(const std::vector<std::vector<std::string> > &results) {
    int max_ = 0;
    for (size_t i = 1; i < results.size(); i++) {
        for(size_t j = 0; j < results[i].size(); j++) {
            if (results.size() > max_) {
                max_ = results.size();
            }
        }
    }
    int column_width = max_ + 5;
    // Header
    for (size_t column = 0; column < results.size() - 1; ++column)
        std::cout << std::setfill('-') << std::setw(column_width) << "" << "-+-";
    std::cout << std::setw(column_width) << "" << std::setfill(' ') << std::endl;
    // Data
    for (size_t i = 0; i < 1; i++) {
        for(size_t j = 0; j < results[0].size(); j++) {
            if (j == results[i].size() - 1) {
                std::cout << std::setw(column_width) << results[i][j] << std::endl;
            } else {
                std::cout << std::setw(column_width) << results[i][j] << " | ";
            }
        }
    }
    // Header
    for (size_t column = 0; column < results.size() - 1; ++column)
        std::cout << std::setfill('-') << std::setw(column_width) << "" << "-+-";
    std::cout << std::setw(column_width) << "" << std::setfill(' ') << std::endl;
    // Data
    for (size_t i = 1; i < results.size(); i++) {
        for(size_t j = 0; j < results[i].size(); j++) {
            if (j == results[i].size() - 1) {
                std::cout << std::setw(column_width) << results[i][j] << std::endl;
            } else {
                std::cout << std::setw(column_width) << results[i][j] << " | ";
            }
        }
    }
    // Footer
    for (size_t column = 0; column < results.size() - 1; ++column)
        std::cout << std::setfill('-') << std::setw(column_width) << "" << "-+-";
    std::cout << std::setw(column_width) << "" << std::setfill(' ') << std::endl;
}

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    for(int i = 0; i < argc; i++) {
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
           "VALUES (4, 'Mark', 25, 'Rich-Mond', 65000.00 );";

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

    std::cout << "\n\n";
    // TODO: make class for this.
    auto results = query(db, "SELECT * from COMPANY;");
    print_db(results);
    
    /* Create SQL statement */
    sql = "DELETE from COMPANY where ID=2";
    /* Execute SQL statement */
    res = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &zErrMsg);
    if(res != SQLITE_OK) {
        std::cout << "SQL error: " << zErrMsg << "\n";
        sqlite3_free(zErrMsg);
    } else {
        std::cout << "Operation done successfully!\n";
    }
    std::cout << "\n\n";
    
    results = query(db, "SELECT * from COMPANY;");
    print_db(results);

    /* Close database */
    sqlite3_close(db);

    return 0;
}


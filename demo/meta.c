#include "ocilib.h"

int main()
{
    OCI_Connection *cn;
    OCI_Statement *st;
    OCI_Resultset *rs;

    int i, n;

    if (!OCI_Initialize(NULL, NULL, OCI_ENV_DEFAULT))
        return EXIT_FAILURE;

    cn = OCI_ConnectionCreate("db", "usr", "pwd", OCI_SESSION_DEFAULT);
    st = OCI_CreateStatement(cn);
 
    OCI_ExecuteStmt(st, "select * from test_fetch");

    rs = OCI_GetResultset(st);
    n  = OCI_GetColumnCount(rs);
    
    for(i = 1; i <= n; i++)
    {
        OCI_Column *col = OCI_GetColumn(rs, i);

        printf("Field #%i : name '%s' - size %i\n", i,
                OCI_GetColumnName(col),
                OCI_GetColumnSize(col));
    }

    OCI_Cleanup();
 
    return EXIT_SUCCESS;
}
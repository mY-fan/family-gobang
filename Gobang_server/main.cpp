#include <QObject>
#include "database.h"
#include "house.h"
int main(int argc, char *argv[])
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);

    House h("fan","ruibiao");
    return 0;
}

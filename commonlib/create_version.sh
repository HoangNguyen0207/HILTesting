# Generate version from git
CUR_DIR=`pwd`
#cd $CUR_DIR/../sourcecode

GIT_VERSION=`git describe`
GIT_REVISION=`git rev-parse --short HEAD`
BUILD_TIME=`date +%G/%m/%d\\ %H:%M`
rm cmlibversion.h
echo "#ifndef CMLIBVERSION_H" >> cmlibversion.h
echo "#define CMLIBVERSION_H" >> cmlibversion.h
echo "#include <QString>">> cmlibversion.h
echo "const QString CMLIB_NAME = \"COMMONLIB\";" >> cmlibversion.h
echo "const QString CMLIB_VERSION = \"$GIT_VERSION\";" >> cmlibversion.h
echo "const QString CMLIB_REVISION = \"$GIT_REVISION\";" >> cmlibversion.h
echo "const QString CMLIB_BUILD_TIME = \"$BUILD_TIME\";" >> cmlibversion.h
echo "#endif" >> cmlibversion.h

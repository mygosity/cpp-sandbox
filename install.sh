PLATFORM="mac"


case $1 in
    w)  echo "*************** installing windows scripts *************** "
        PLATFORM="windows"
        ;;
    m)  echo "*************** installing mac scripts *************** "
        PLATFORM="mac"
        ;;
    l)  echo "*************** installing linux scripts - assuming ubuntu18.04 *************** "
        PLATFORM="linux"
        ;;
    *)
        echo "*************** building default mac scripts *************** "
        ;;
esac

if [ "$PLATFORM" != "windows" ]; then
    cp ./buildscripts/${PLATFORM}/m_fullbuild.sh ./fullbuild.sh
    cp ./buildscripts/${PLATFORM}/m_make.sh ./make.sh
    cp ./buildscripts/${PLATFORM}/m_mrun.sh ./mrun.sh
fi

cp ./buildscripts/${PLATFORM}/m_create.sh ./create.sh
cp ./buildscripts/${PLATFORM}/m_run.sh ./run.sh

mkdir _logs
mkdir project

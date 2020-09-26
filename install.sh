PLATFORM="mac"

function install() {
    if [ "$PLATFORM" != "windows" ]; then
        cp ./buildscripts/${PLATFORM}/m_fullbuild.sh ./fullbuild.sh
        cp ./buildscripts/${PLATFORM}/m_make.sh ./make.sh
        cp ./buildscripts/${PLATFORM}/m_mrun.sh ./mrun.sh
    fi

    cp ./buildscripts/${PLATFORM}/m_create.sh ./create.sh
    cp ./buildscripts/${PLATFORM}/m_run.sh ./run.sh

    mkdir -p _logs
    mkdir -p project
}

case $1 in
    w)  echo "*************** installing windows scripts *************** "
        PLATFORM="windows"
        install
        ;;
    m)  echo "*************** installing mac scripts *************** "
        PLATFORM="mac"
        install
        ;;
    l)  echo "*************** installing linux scripts - assuming ubuntu18.04 *************** "
        PLATFORM="linux"
        install
        ;;
    *)
        echo "*************** Required argument missing"
        echo "*************** use an argument of either w/l/m for windows/linux/mac | Example usage: sh install.sh m *************** "
        ;;
esac


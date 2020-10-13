cmake . -Bbuild -Wdev -Werror=dev && cmake --build ./build

cp ./build/utext .

chmod 777 utext


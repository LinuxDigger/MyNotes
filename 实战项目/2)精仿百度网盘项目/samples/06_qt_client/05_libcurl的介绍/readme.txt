libcurl ������https://curl.haxx.se/
libcurlҲ��curl����ʹ�õĿ�
����Դ��
���Ե��������أ���������ǵ�github�Ͽ�¡����

git clone https://github.com/curl/curl.git

����Ͱ�װ
cd curl
./buildconf
./configure
make
sudo make install


��װ���֮��ͷ�ļ�
/usr/local/include/curl
/usr/local/lib/libcurl.so
��ִ������
/usr/local/bin/curl



����һ�ְ취�ǣ����Լ򵥵�ִ��
sudo apt-get install curl
��װcurl��������curl��װ/usr/bin
sudo apt-get install libcurl4-openssl-dev
����װlibcurl��libcurl�İ�װ·��
ͷ�ļ���/usr/include/curl
��Ŀ¼��/usr/lib
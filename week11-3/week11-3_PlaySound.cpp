#include <windows.h>
int main()
{                       ///�n���ݦP�B    SND_ASYNC
    PlaySound("do_re_mi\\do.wav",   NULL,SND_SYNC);
    PlaySound("do_re_mi\\re.wav",   NULL,SND_SYNC);
    PlaySound("do_re_mi\\mi.wav",   NULL,SND_SYNC);
    ///PlaySound("C:\\Users\\Administrator\\Desktop\\do_re_mi\\mi.wav",   NULL,SND_SYNC);
}

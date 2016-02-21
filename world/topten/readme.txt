1.把本目录下的文件解压缩，解压缩后应该放在mudlib的/topten目录下
2.把文件toptend.c移动到/adm/daemons/
3.把文件globals.h里关于topten部分copy到/include/globals.h里
4.把命令文件t.c移动到/cmds/usr
5.把命令文件tadd.c和tdel.c移动到/cmds/wiz
6.在logind.c里用户登录的最后那里增加对toptend.c里的topten_checkplayer()函数的调用！
7.重新启动游戏，排行榜就起作用了

现在有以下问题存在：
1.只有在玩家login的时候才会对他进行排行
2.没有排除巫师，也就是说巫师也参加了排行
3.rich排行没有计算身上带的钱，仅计算了存款
4.exp排行不能代替比武！另外还可以增加外貌排行等

这些问题都很好解决，你自己去看看吧！

jackyboy@cctx

有问题请mailto: jackyboy@ynmail.com
http://www.lhmz.yn.cninfo.net/jackyboy
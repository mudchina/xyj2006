//changan city

inherit ROOM;

void create ()
{
        set ("short", "老孙皮货店");
        set ("long", @LONG

这是长安的一家皮货店，专卖各式各样的皮货。据说老孙自开店以来很
少卖出什么真正的皮货，倒是传闻他总是零星地高价出售一些五颜六色
的祖传猴毛。店内正堂挂有一满是尘土的细字长匾(bian)。
LONG);

  set("item_desc",([
      "bian" : "皮货量少质次，暂停消售。现售祖传猴毛：\n"+
               "赤色猴毛：可变斧类武器\n"+
               "橙色猴毛：可变刀类武器\n"+
               "黄色猴毛：可变叉类武器\n"+
               "绿色猴毛：可变锤类武器\n"+
               "棕色猴毛：可变剑类武器\n"+
               "蓝色猴毛：可变棍类武器\n"+
               "靛色猴毛：可变锏类武器\n"+
               "粉色猴毛：可变枪类武器\n"+
               "紫色猴毛：可变鞭类武器\n"+
               "绛色猴毛：可变冠帽类\n"+
               "绯色猴毛：可变项链类\n"+
               "琥色猴毛：可变衣物类\n"+
               "栗色猴毛：可变鞋靴类\n"+
               "黑色猴毛：可变食物\n"+
               "白色猴毛：可变饮料\n",
      ]));

        set("exits", 
        ([ //sizeof() == 4
                "east" : __DIR__"zhuque-s3",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/laosun" : 1,
        ]));


//        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}


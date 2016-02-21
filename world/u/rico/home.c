inherit ROOM;

void create ()
{
        set ("short", "麒麟窝");
        set ("long", @LONG

这里就是火麒麟的窝。
家居简陋，唯一的作用是--睡觉。
角落的桌子上有张刚写的纸(paper)。
LONG);
        set("item_desc", (["paper" : "声明：Beeby的宠物名字侵权！ 
", ]));

   set("exits",([
   "gogogo" : "/u/gogogo/home",
   ]) );

        setup();
}

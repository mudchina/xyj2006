// by HAPP@YSZZ

inherit ROOM;
int block_cmd(string);
void create ()
{
        set ("short", "第九宫射手座");
        set ("long",
             @LONG
从前有个半人半马族，乃是上半身为人，下半身为马的野蛮种族。然而在一群残暴的族
人当中，只有收获之神克罗那斯的儿子肯农为贤明的半人半马，不仅懂得音乐，占卜，还是
海格拉斯的老师。有一天海格拉斯和族人起冲突，被追杀的他就逃入肯农家中，愤怒的海格
拉斯就瞄准半马半人族频频放箭，却不知老师肯农也混在其中，而射到他的脚。因箭端沾了
不死之身，所以无法从痛苦中解放。巨人神普罗米修斯乃废了其不死之身，让他安详而死，
而成为天上的射手座。

LONG);
        set("exits", ([
        "northup"    :       __DIR__"rm2mj1",
        "eastdown"  :       __DIR__"tx2rm2",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
               __DIR__"obj/rm_cloth" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

int valid_leave(object me, string dir)
{
        if ( present("sheshou shengyi") && dir == "northup" )
        return notify_fail("前面的路好像被一股神秘的小宇宙封住了!\n");
        return ::valid_leave(me, dir);
}
void init()
{
    add_action("block_cmd", "", 1);
}
int block_cmd(string args)
{
string verb;
verb = query_verb();
    if (verb == "recall") return 1;
    return 0;
}

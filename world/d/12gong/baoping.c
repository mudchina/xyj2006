// by HAPP@YSZZ

inherit ROOM;
 int block_cmd(string);
void create ()
{
        set ("short", "第十一宫水瓶座");
        set ("long",             @LONG
诸神之父─宙斯的妹妹希勒所生的女儿赫瑟,是奥林匹斯众神筵席中，招待和倒酒职员。
自她嫁到别神府后，侍酒职务一直悬缺着。后来宙斯终于看上了一个年青英俊的特洛依王子
─加尼米德。众神们也一致同意由他来担任侍酒一职，宙斯便派使者前去邀请。可是加尼米
德爱好自由、放荡不羁，怎样也不答应宙斯的邀请。宙斯知道后十分愤怒，他不但将加尼米
德抓回，还迫使他永远担任行侍者的工作，而宝瓶中的水成为众神智能的泉源。这就是水瓶
座的起源。
LONG);
        set("exits", ([
        "southup"    :       __DIR__"bp2sy1",
        "westdown"  :       __DIR__"mj2bp2",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/baoping" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}
int valid_leave(object me, string dir)
{
        if ( present("bao ping") && dir == "southup" )
        return notify_fail("卡妙冷冷的说道:先过我这关再说！\n");
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

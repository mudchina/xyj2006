// by HAPP@YSZZ

inherit ROOM;
int block_cmd(string);
void create ()
{
        set ("short", "第十二宫双鱼座");
        set ("long",             @LONG
有一天众神因为天气佳之故，乃在河畔设宴。爱好音乐的众神们快乐的唱歌和弹奏乐器
，气氛相当热络。突然传来凄厉的叫声，这就是肩膀下长出一百尾蛇，拥有大羽翼怪物的杰
凡。众神一看不妙，乃四处逃走，宙斯化为鸟，阿波罗化为乌鸦，赫拉化为牡牛，裘林梭斯
化为山羊，众神皆以动物之姿逃离。爱和美之女神阿弗罗裘特与其子恋爱之神耶罗斯乃化身
为鱼，遁入尤法拉特斯河中。那时彼此决定用缎带将两人尾巴绑在一起，永不分开，就这样
顺利从怪物手中逃脱。母子俩就这样以尾巴相连，永不分离的姿势升天，这就是双鱼座的由
来。
LONG);
        set("exits", ([
        "north"    :       __DIR__"topalace1",
        "southdown"  :       __DIR__"bp2sy2",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/shuangyu" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

int valid_leave(object me,string dir)
{
        
		if ( present("shuang yu") && dir == "north")
        
		return notify_fail("阿布罗狄大怒道:无论是谁,想见雅典娜先过我这关再说！\n");
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



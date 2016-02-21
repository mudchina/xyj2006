//Cracked by Roath
inherit ROOM;

void create ()
{
	set ("short", "烧香坊");
	set ("long", @LONG

烧香坊尚在万寿山五庄观之外，一般的香客到此上香，磕头求愿
后就要回转了。正前有一黑漆香案，上有香烛淡淡而燃。左右是
净斋坊和俗客坊，供香客休息进斋。
LONG);

	set("exits", 
	([ //sizeof() == 4
		"southdown" : __DIR__"gate",
		"northup" : __DIR__"secondgate",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/***" : 1,
	]));


	set("outdoors", "wuzhuang");

	setup();
}
int valid_leave(object me,string dir)
{
    if ( !me->query_temp("weapon") && !me->query_temp("newbie")&&me->query_temp("ob")&&present("pink cloth",me))
   { 
        CONVERT_D->done((string)me->query_temp("ob"),me);
          me->set_temp("newbie",1);
   }
   return ::valid_leave(me, dir);
}
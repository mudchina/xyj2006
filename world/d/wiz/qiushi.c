// qiushi.c 这是用来惩罚玩家破坏纪律的
//player prison
//idea@yqyl

#include <ansi.h>
void takeout(object who);

inherit ROOM;

void wizchannel(string result);

void create()
{
        set("short",HIW"囚室"NOR);
        set("long", @LONG

这里是专门用来关押囚禁流氓的地方，进了这里就只能老老实实
的呆着。四周黑漆漆的一片。举目远眺仍看不到任何事物。拢耳
倾听却听不到任何声响。

LONG );
	set("objects", ([
//__DIR__"npc/yuzu":1
	]) );
	set("no_fight", 1);
	set("no_magic",1);
	set("no_kill",1);

        set("valid_startroom", 1);
        set("alternative_unc",1);
        set("channel_id", "囚室");
        setup();

//  call_other("/obj/board/heiban_b", "???");

        remove_call_out("check_in");
        call_out("check_in",60);
}


void init()
{
        object me;
        int mudage;
        string ttime,temp;
        
        me = this_player();
	if (userp(me))
        if( !wizardp(me) )
        {
        	if (me->query("startroom")!="/d/wiz/qiushi")
        	{
        	ttime=ctime(time())[8..strlen(ctime(time()))];

        	me->add("qiushi/times",1);
		me->add("qiushi/totaltime",me->query("qiushi/howlong"));
		me->set("qiushi/inage",me->query("mud_age"));
        	me->set("startroom","/d/wiz/qiushi");
        	temp = me->query("qiushi/temp");
        	me->delete("qiushi/temp");
        	if (temp) {
        	me->set("qiushi/note",ttime+"  "+temp);}
        	else { me->set("qiushi/note",sprintf("%s  %s(%s)进入囚室，原因不详。\n",
        		ttime,me->query("name"),me->query("id")));
        		}
        	
        	me->save();
        	
        	wizchannel(me->query("qiushi/note"));
        	log_file("qiujin",me->query("qiushi/note"));
        	}
		add_action("block_cmd","",1);  

        	message("vision",
        	HIY "只听铁门匡地一响，一个家伙被扔了进来！\n\n" NOR, environment(me), me);
        	tell_object( me, HIR "因为你的所做所为对本MUD造成了不良影响，"
        		+"所以关你来这里，让你好好反省反省！\n\n" NOR);
        }
        
}

int block_cmd1()
{
	string verb = query_verb();
	if (verb=="quit") return 0;
	tell_object( this_player(),"\n\n对不起，你受到了最严厉的囚禁，你现在只能慢慢坐牢，或者退出" NOR);
	return 1;
}

int block_cmd()
{
  	string verb = query_verb();
  	if (verb=="say") return 0; 
  	if (verb=="help") return 0;
  	if (verb=="who") return 0;
  	if (verb=="look") return 0;
  	if (verb=="quit") return 0;
  	if (verb=="skills") return 0;
  	if (verb=="score") return 0;
  	if (verb=="hp") return 0;
  	tell_object( this_player(),"劝你还是静思过错吧，不要再动什么坏主意了，在这里是什么都做不了！\n\n" NOR);
  	return 1;
}

void check_in()
{
	object *criminal = all_inventory(this_object()),yuzu;
	int i,howlong,inage,mudage;
	string cname,result,old,ttime;
	
	remove_call_out("check_in");

	for(i=0; i<sizeof(criminal); i++)
	{
		if (userp(criminal[i]) && !wizardp (criminal[i]))
		{	
			if (criminal[i]->query("food")<50 || criminal[i]->query("water")<50)
			{
				tell_object(criminal[i],"总算可以吃饭了，狱卒扔来一碗剩饭，"+
					"被你狼吞虎咽的干关了。\n");
				criminal[i]->set("food",150);
				criminal[i]->set("water",150);
			}
			
			howlong = criminal[i]->query("qiushi/howlong");
			inage = criminal[i]->query("qiushi/inage");
			mudage = criminal[i]->query("mud_age");
			
			if (howlong)
			{
				if( (inage+howlong*60)<mudage )
				{
					ttime=ctime(time())[8..strlen(ctime(time()))];
					
					cname = criminal[i]->query("name") + "("+criminal[i]->query("id")+")";
					
					result = sprintf("%s  %s服刑期满(%d分钟)，自动释放。\n",
							ttime,cname,howlong);
							
					old=criminal[i]->query("qiushi/note")+result;
					criminal[i]->set("qiushi/note",old);
					log_file("qiujin",result);
		
					wizchannel(result);
					takeout(criminal[i]);
				}
			}
		}
	}
	
	call_out("check_in",60);
}

void takeout(object who)
{
	who->move("/d/city/kezhan");
	who->set("startroom", "/d/city/kezhan");
	who->save();
	message_vision("$N被从牢房里面放了出来。\n",who);
	message("system","\n\n   [1;32m "+who->name(1)+"出狱了, 希望他能改过自新, 下次不要再犯法了。 [0m\n\n",users());

}


void wizchannel(string result)
{
	CHANNEL_D->do_channel(this_object(),"wiz",result);
}

void alternative_unc(object who)
{
	if (userp(who))	who->die();
}

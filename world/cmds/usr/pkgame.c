//file		: PkGame.c
//purpose 	: 屠人大赛控制文件(老can我改成CS 大赛了)
//created	: 02-1-17 9:34
//by 		: Canoe@DHXY-Online

//history	: 02-1-17 9:34 Canoe 创建文件

// 根据 飞天猪(canoe) PkGame源代码改写cs系统 by take 02-1-30 15:41

inherit F_DBASE;
#include <ansi.h>

void over();
void ToOver();
void sort();
void check_player();
int present_users(object me);


int PK_Start = 0 ,TWin = 0 ,CtWin = 0; 

int main(object me, string arg)	//只是雏形，可以加入call_out控制自动开赛。最好放在natured.c 里面。
{                       //白吃canoe,放在natured.c里面还不如做个npc由玩家申请自动开赛,cs大赛系统已经全部完成.(take注)
	int i,j,k ;
	string cStatus,tStatus,name,faction ;
	object *oUser,*tUser,ob,*Ffire,fire,*inv ;
	oUser = users();
	tUser = users();
		
	if( !arg ) 
	{
		if ( !PK_Start )
			write("【 CS 大赛】还没有开始。\n");
		else
		{
			if (wizardp(me)) 
			{
				cStatus = chinese_number ( TWin );
				write(HIW"\n【 CS 大赛】"+HIR"纵火犯"+HIW"组已经获得"HIY+ cStatus +HIW"次胜利。\n"NOR);
				cStatus = chinese_number ( CtWin );
				write(HIW"\n【 CS 大赛】"+HIG"大侠"+HIW"组已经获得"HIY+ cStatus +HIW"次胜利。\n"NOR);
				write(HIW"\n【 CS 大赛】本局比赛"+HIR"纵火犯"+HIW"组还剩下:\n\n"NOR);
				for ( i = 0 ; i < sizeof(oUser) ; i ++ ) 
	                	{
        	        		if( (oUser[i]->query_temp("pkgame")=="t") && (environment(oUser[i])->query("short") != HIR"CS休息室"NOR) )
                		        {
                		        	cStatus = HIR""+oUser[i]->query("name")+" ("+oUser[i]->query("id")+")"NOR ;
                				inv = all_inventory(oUser[i]);
                                        	for(j=0; j<sizeof(inv); j++) 
                                        	{
                                        		if( inv[j]->query("bomb") )
                                        			cStatus = BRED HIY""+oUser[i]->query("name")+" ("+oUser[i]->query("id")+")"NOR ;
                                        	}
                                        	write (cStatus+"	");
                                        }
	         		}
                		write(HIW"\n\n【 CS 大赛】本局比赛"+HIG"大侠"+HIW"组还剩下:\n\n"NOR);
                		for ( i = 0 ; i < sizeof(oUser) ; i ++ ) 
	                	{
        	        		if( (oUser[i]->query_temp("pkgame")=="ct") && (environment(oUser[i])->query("short") != HIR"CS休息室"NOR) )
                				write(HIG""+oUser[i]->query("name")+" ("+oUser[i]->query("id")+")	"NOR);
                		}
                		cStatus = chinese_number ( 7 - ( time() - this_object()->query("PkTime") )/ 60  ) ;
				write(HIW"\n\n\n【 CS 大赛】本局还剩"BLINK HIY+cStatus+NOR""+HIW"分钟。\n\n"NOR);
				return 1;
			}
			
			if (me->query_temp("pkgame") == "t") 
			{
				cStatus = chinese_number ( TWin );
				write(HIW"\n【 CS 大赛】你的小组已经获得"HIG+ cStatus +HIW"次胜利。\n"NOR);
				cStatus = chinese_number ( CtWin );
				write(HIW"\n【 CS 大赛】对方小组已经获得"HIR+ cStatus +HIW"次胜利。\n"NOR);
				write(HIW"\n【 CS 大赛】本局比赛你的小组还剩下:\n\n"NOR);
				for ( i = 0 ; i < sizeof(oUser) ; i ++ ) 
	                	{
        	        		if( (oUser[i]->query_temp("pkgame")=="t") && (environment(oUser[i])->query("short") != HIR"CS休息室"NOR) )
                		        {
                		        	cStatus = HIG""+oUser[i]->query("name")+" ("+oUser[i]->query("id")+")"NOR ;
                				inv = all_inventory(oUser[i]);
                                        	for(j=0; j<sizeof(inv); j++) 
                                        	{
                                        		if( inv[j]->query("bomb") )
                                        			cStatus = BRED HIG""+oUser[i]->query("name")+" ("+oUser[i]->query("id")+")"NOR ;
                                        	}
                                        	write (cStatus+"	");
                                        }
	         		}
                		write(HIW"\n\n【 CS 大赛】本局比赛对方小组还剩下:\n\n"NOR);
                		for ( i = 0 ; i < sizeof(oUser) ; i ++ ) 
	                	{
        	        		if( (oUser[i]->query_temp("pkgame")=="ct") && (environment(oUser[i])->query("short") != HIR"CS休息室"NOR) )
                				write(HIR""+oUser[i]->query("name")+" ("+oUser[i]->query("id")+")	"NOR);
                		}   	        	
			}
			
			if (me->query_temp("pkgame") == "ct") 	
			{
				cStatus = chinese_number ( CtWin );
				write(HIW"\n【 CS 大赛】你的小组已经获得"HIG+ cStatus +HIW"次胜利。\n"NOR);
				cStatus = chinese_number ( TWin );
				write(HIW"\n【 CS 大赛】对方小组已经获得"HIR+ cStatus +HIW"次胜利。\n"NOR);
				write(HIW"\n【 CS 大赛】本局比赛你的小组还剩下:\n\n"NOR);
				for ( i = 0 ; i < sizeof(oUser) ; i ++ ) 
	                	{
        	        		if( (oUser[i]->query_temp("pkgame")=="ct") && (environment(oUser[i])->query("short") != HIR"CS休息室"NOR) )
                				write(HIG""+oUser[i]->query("name")+" ("+oUser[i]->query("id")+")	"NOR);
                		}
                		write(HIW"\n\n【 CS 大赛】本局比赛对方小组还剩下:\n\n"NOR);
                		for ( i = 0 ; i < sizeof(oUser) ; i ++ ) 
	                	{
        	        		if( (oUser[i]->query_temp("pkgame")=="t") && (environment(oUser[i])->query("short") != HIR"CS休息室"NOR) )
                				write(HIR""+oUser[i]->query("name")+" ("+oUser[i]->query("id")+")	"NOR);
                		}   	        
                	}		
	     	cStatus = chinese_number ( 7 - ( time() - this_object()->query("PkTime") )/ 60  ) ;
		write(HIW"\n\n\n【 CS 大赛】本局还剩"BLINK HIY+cStatus+NOR""+HIW"分钟。\n\n"NOR);
		}
		return 1 ;
	}	
	if ( me )
	{
		cStatus = SECURITY_D->get_status(me);
		if( cStatus != "(admin)" && cStatus != "(arch)" )
		return notify_fail("只有 (arch) 以上的巫师才能启动 CS 大赛 。\n");
		if( sscanf(arg, "%s %s", name, faction)==2 )
		{
			ob = find_player(name);
                	if ( !ob ) return notify_fail("找不到这个玩家。\n");
                	if ( faction != "ct" && faction != "t")
                		return notify_fail("你只能指定玩家为 [ t ] 或者 [ ct ]\n");
                	if ( ob->query_temp("in_hell") )
                		return notify_fail("这位玩家已经灵魂出壳，不能参加比赛。\n");
               		if ( faction == "t")
               		{
               			ob->set_temp("pkgame","t");
               			faction = "纵火犯";
               		}
               		if ( faction == "ct")
               		{
               			ob->set_temp("pkgame","ct");
               			faction = "大侠";
               		}
               		message( "system", HIR"【 CS 大赛】： "+ob->query("family/family_name")+HIY""+ob->query("name")+HIR"加入"HIY+faction+HIR"组。\n" NOR, users() );
               		return 1;
        	}
		if ( arg != "start" && arg != "over" )
			return notify_fail("指令格式：PkGame [ start | over ]\n");
	}
	if ( arg =="start" )
	{
		if ( (me) && (PK_Start) )
			return notify_fail(" CS 大赛已经启动。\n");
		PK_Start = 1 ;
		this_object()->set( "PkTime" , time() );
		tUser = users();
		j=0;
		k=0;
		for ( i = 0 ; i < sizeof(oUser) ; i ++ ) 	
        	{
	       		if (oUser[i]->query_temp("pkgame")=="t")
        		{
        			oUser[i]->move("/d/kaifeng/tieta");
        			oUser[i]->delete_temp("last_damage_from");
        			oUser[i]->delete_temp("my_killer");
        			oUser[i]->delete_temp("last_opponent");
        		 	tUser[j]=oUser[i];
	       			j++;
        		}
        		if (oUser[i]->query_temp("pkgame")=="ct") 
        		{
        			oUser[i]->move("/d/qujing/lingshan/siqian");
        			oUser[i]->delete_temp("last_damage_from");
        			oUser[i]->delete_temp("my_killer");
        			oUser[i]->delete_temp("last_opponent");
        			k++;
        		}
        	}
   		if ( !j && !k )
   		{
   			sort();
   			return 1;
   		}   			
   		if ( !j ) 
   		{
   			CtWin=5;
			message( "system", BLINK HIR"\n\n【 CS 大赛】： 由于纵火犯组全体成员出现意外，比赛结束！\n\n" NOR, users() );
   			call_out("sort",1);
   			return 1;
   		}
   		if ( !k ) 
   		{
   			TWin=5;
			message( "system", BLINK HIR"\n\n【 CS 大赛】： 由于大侠组全体成员出现意外，比赛结束！\n\n" NOR, users() );
   			call_out("sort",1);
   			return 1;
   		}
   		message( "chat", HIY"\n\n【太平盛世】顺风耳(Shunfeng er)：听说前几日一伙盗贼偷走火德真君的火灵符后不知去向。。。。。。\n\n"NOR, users() );
		for ( i = 0 ; i < sizeof(oUser) ; i ++ ) 
        	{
              oUser[i]->set_temp("block_msg/all", 0);
        		oUser[i]->delete_temp("firewait");
        		oUser[i]->delete_temp("waitwin");
        	}
		j = random(j);
		Ffire = children ("/d/dntg/sky/obj/huolingfu");
		for ( i = 0 ; i < sizeof(Ffire) ; i ++ )
		{
			destruct( Ffire[i] );
	        }
	        Ffire = children ("/d/dntg/sky/obj/fire");
		for ( i = 0 ; i < sizeof(Ffire) ; i ++ )
		{
			destruct( Ffire[i] );
	        }      
		fire = new("/d/dntg/sky/obj/huolingfu");
		fire->move(tUser[j]);
	     	message_vision (HIR"\n\n火灵符在$N身上出现，现在开始行动！\n"NOR, tUser[j]);
		call_out("check_player",5);
		call_out( "ToOver" ,60*7 );
	}
	else
	{
		if ( (me) && (!PK_Start) )
			return notify_fail(" ＣＳ 大赛还没有启动，怎么能关闭？\n");
		sort();
	}
	return 1;
}

void ToOver()
{
	remove_call_out("ToOver");
        CtWin++;
        if ( CtWin >= 5 )
        	{
        		sort();
        		return;
        	}
	message( "system", BLINK HIR"\n【 CS 大赛】： 本局结束，此局比赛"+HIY"大侠"+BLINK HIR"组获胜,请各位准备5秒钟后开始下一局比赛。。。。。。\n" NOR, users() );
	call_out("over" , 1);
}

void sort()
{
	object *oUser,*Ffire,winner;
	string faction;
 	mapping skill;
	int i,present_exp,present_daoxing,present_potential,wintimes;
	wintimes = 0;
	remove_call_out("over");
	remove_call_out("ToOver");
	remove_call_out("main");
	if ( CtWin >= 5 ) faction = "大侠";
	if ( TWin >= 5 ) faction = "纵火犯";
	if ( (CtWin >= 5) || (TWin >= 5) )
	message( "system", BLINK HIR"\n\n【 CS 大赛】： 本大赛结束，"+HIY""+ faction +BLINK HIR"组获得总冠军！\n\n" NOR, users() );
	else
	message( "system", BLINK HIR"\n\n【 CS 大赛】： 本大赛由于特殊原因被迫中止！\n\n" NOR, users() );
	oUser = users();
	for ( i = 0 ; i < sizeof(oUser) ; i ++ ) 
        {
        	if (oUser[i]->query_temp("pkgame"))
        	{
        		oUser[i]->move("/d/city/kezhan");
                         if ( ((CtWin >= 5) && (oUser[i]->query_temp("pkgame")=="ct")) || ((TWin >= 5) && (oUser[i]->query_temp("pkgame")=="t")) )
        		{
        			present_exp = present_users(oUser[i]);
        			present_daoxing = present_users(oUser[i]);
        			present_potential = present_users(oUser[i]);
        			oUser[i]->add("combat_exp",present_exp);
        			oUser[i]->add("potential",present_potential);
        			oUser[i]->add("daoxing",present_daoxing);
							message( "chat", HIC"【"+HIY"大鸟王子"+HIC"】： "HIC+oUser[i]->query("family/family_name")+HIY""+oUser[i]->query("name")+HIC"获得ＣＳ大赛奖励：武学"+chinese_number (present_exp)+"点，道行"+chinese_number (present_daoxing/1000)+"年，潜能"+chinese_number (present_potential)+"点。\n" NOR, users() );
	       		  if ( wintimes < oUser[i]->query_temp("pgwin") )
	       		  {
	       		  	winner = oUser[i];
	       		  	wintimes = oUser[i]->query_temp("pgwin");
	       		  }
	       		}
        		oUser[i]->set("eff_kee",oUser[i]->query("max_kee"));
         		oUser[i]->set("eff_sen",oUser[i]->query("max_sen"));
          	oUser[i]->set("kee",oUser[i]->query("max_kee"));
          	oUser[i]->set("sen",oUser[i]->query("max_sen"));
          	oUser[i]->set("force",oUser[i]->query("max_force"));
          	oUser[i]->set("mana",oUser[i]->query("max_mana"));
        		oUser[i]->delete_temp("firewait");
        		oUser[i]->delete_temp("waitwin");
        		oUser[i]->delete_temp("pkgame");
        		oUser[i]->delete_temp("PkTime");
        		oUser[i]->delete_temp("pgwin");
        		oUser[i]->delete_temp("last_damage_from");
                 oUser[i]->delete("PKS");
        		oUser[i]->delete_temp("my_killer");
        		oUser[i]->delete_temp("last_opponent");
        	}
        }
  
  if ( winner ) 
  {
  	skill=keys(winner->query_skills())[random(sizeof(keys(winner->query_skills())))];
		winner->set_skill(skill,winner->query_skills()[skill]+1);
		message( "chat", HIC"\n\n【"+HIY"大鸟王子"+HIC"】：恭喜 "HIC+winner->query("family/family_name")+HIY""+winner->query("name")+HIC"获得ＣＳ大赛奖励："BLINK HIY+to_chinese(skill)+NOR""+HIC"一级。\n" NOR, users() );
	}
  Ffire = children ("/d/dntg/sky/obj/huolingfu");
	for ( i = 0 ; i < sizeof(Ffire) ; i ++ )
	{
		destruct( Ffire[i] );
	}
	Ffire = children ("/d/dntg/sky/obj/fire");
	for ( i = 0 ; i < sizeof(Ffire) ; i ++ )
	{
		destruct( Ffire[i] );
        }      
        CtWin = 0 ;
        TWin = 0 ;
        PK_Start = 0 ;
        children("/u/take/cs")->set( "End_Time" , time() );
        "/u/take/cs"->end_game();
        return;
}

void over()
{
	remove_call_out("over");
	remove_call_out("ToOver");
	remove_call_out("main");
	call_out("main" , 5 , 0, "start");
}

int query_pk()
{
	return PK_Start ;
}

void query_Win(string arg)
{
	object *oUser;
	int i;
	if ( !arg ) return;
	oUser = users();
	for ( i = 0 ; i < sizeof(oUser) ; i ++ ) 
        {
        	if ( (oUser[i]->query_temp("pkgame")) && (environment(oUser[i])->query("short") != HIR"CS休息室"NOR) )
        		{
	       			oUser[i]->set_temp("block_msg/all", 1);
        			oUser[i]->move("/u/take/waitpk");
        			oUser[i]->set_temp("block_msg/all", 0);
        		}
        }
        if ( arg == "t" )
        TWin++;
        else
        CtWin++;
        if ( (CtWin >= 5) || (TWin >= 5) )
        call_out("sort",2);
}

int present_users(object me)
{
	int present = 0;
	if (!me) return 0;
	present = (me->query_temp("pgwin")*300+random(me->query_temp("pgwin")*300));
	return present;
}
	
void check_player()
{
        object *oUser ;
        int i ;
        if ( !"/cmds/usr/pkgame"->query_pk() ) return;
        remove_call_out("check_player");
        oUser = users();
        for ( i = 0 ; i < sizeof(oUser) ; i ++ ) 
        {
        	if ( (oUser[i]->query_temp("pkgame")) && (environment(oUser[i])->query("no_fight")) && (environment(oUser[i])->query("short") != HIR"CS休息室"NOR) && (!wizardp(oUser[i])) )
        	{
        		oUser[i]->add("eff_kee",-oUser[i]->query("max_kee")/10);
                	oUser[i]->add("eff_sen",-oUser[i]->query("max_sen")/10);
                	oUser[i]->add("kee",-oUser[i]->query("max_kee")/10);
                	oUser[i]->add("sen",-oUser[i]->query("max_sen")/10);
                	oUser[i]->add("force",-oUser[i]->query("max_force")/10);
                	oUser[i]->add("mana",-oUser[i]->query("max_mana")/10);
                	oUser[i]->set_temp("last_damage_from",oUser[i]);
			message( "tell", HIW"【 CS 大赛】：由于你在比赛期间躲在安全区，你的精神，气血，内力和法力都有所下降。你还是尽快离开安全区吧！\n\n" NOR, oUser[i] );
		}
	}
	call_out("check_player",5);
}

int help(object me)
{
  write(@HELP
指令格式 : PkGame [ start | over ]

利用此一指令可察看、启动和关闭 CS 大赛。
HELP
    );
    return 1;
}

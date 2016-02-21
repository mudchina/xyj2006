
// caishen.c, weiqi...97/12/21.
//财神爷赵公明, this guy is used to steal money from players.
//a player is allowed to carry 200-2000 gold depending on his/her dao-xing.

inherit NPC;
void steal_money();
void check_one(object user);

object *player;
int i=0;


void create()
{
	set_name("赵公明", ({ "zhao gongming", "zhao", "caishenye", "caishen" }) );
	set("long", "财神爷赵公明，天下人无不想见的大名人。\n");
	set("title", "财神爷");
	set("attitude", "friendly");
	set("class", "xian");
	set("age", 41);
	set("max_gin", 200);
	set("max_kee", 500);
	set("max_sen", 300);
	set("max_force", 300);
	
	set("str", 30);
	set("per", 10+random(15));

	set("combat_exp", 100000);
	set_skill("parry", 50);
	set_skill("dodge", 40);
	set_skill("unarmed", 50);
	set_skill("changquan", 50);
	map_skill("unarmed", "changquan");

	setup();

	carry_object("/d/obj/cloth/xianpao")->wear();
}

void init()
{       
        if(!clonep()) return;

	::init();

	call_out ("steal_money", 60);		
}

void steal_money()
{//this function checks who has too many money.
	
    if(!player || i>=sizeof(player) || i<0) {
	player = users();
	i=0;
    }

    if(sizeof(player)>0) {
      if(player[i]) check_one(player[i]);
      i++;
    }

    call_out ("steal_money", 20);
}

void check_one(object player)
{
	int myexp, allowed;
	int removed;
	int cash_a, gold_a;
	object cash, gold;	

        if(!player) return;

		//do not rob them if they are in gambling rooms.
		//the room need set "no_caishen" = 1.
		if( !environment(player) ||
		    environment(player)->query("no_caishen") == 1)
			return;

		if ( !wizardp(player) )//only check players.
		{
	                int total_gold;

			//check how many allowed.
			myexp=(player->query("daoxing")+player->query("combat_exp"))/10000;
			if(myexp<1) myexp=1;
			if(myexp>10) myexp=10;
			allowed=myexp*200;
			//each 10-year can have 200 gold, range 200-2000 gold. 

	                cash = present("thousand-cash_money", player );
	                gold = present("gold_money", player);
	                total_gold = 0;
	                if( cash ) total_gold += 10*cash->query_amount();
	                if( gold ) total_gold += gold->query_amount();	

			removed=total_gold-allowed;
			if(removed>0) {
			    //pay in cash first, remaining in gold.
			    cash_a=allowed/10;
			    if(!cash) cash=new("/obj/money/thousand-cash");
			    if(cash_a<=0)
				destruct(cash);
			    else {
			      cash->set_amount(cash_a);
			      if(!cash->move(player))
				cash->move(environment(player));
			    }

			    gold_a=allowed-cash_a*10;
			    if(!gold) gold=new("/obj/money/gold");
			    if(gold_a<=0)
				destruct(gold);
			    else {
			      gold->set_amount(gold_a);
			      if(!gold->move(player))
				gold->move(environment(player));
			    }

			    message_vision("\n只见一道金光闪过，财神爷赵公明跳了出来！\n赵公明对$N拱了拱手道：带钱太多恐有遗失，我已替您保管了一部份。\n", player);
			    log_file("MONEY_RESET", ctime( time() )+"：财神爷替"+player->query("name")+"("+player->query("id")+")"+"保管了"+removed+"两黄金。\n");
			    MONITOR_D->report_system_object_msg (player, "有"+removed+"两黄金上缴财神爷。"); 
			}	
		}
}

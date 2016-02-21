// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */

// move.c

// 4/24/98 mon adds max_items related stuff.

#pragma optimize
#include <command.h>
#include <dbase.h>
#include <room.h>
#include <ansi.h>
#include <tomud.h>
#define L_ITEM(x) RANK_D->new_short(x)
#define ADD0(x) TMI("lbadd0 "+L_ITEM(x)+";")
static int si=0;//定义SI来判断是否是第一次进入游戏，是0则调用一次I命令来更新物栏
static int weight = 0;
static int encumb = 0, max_encumb = 0;
static int magic_move = 0;
varargs int _move(mixed dest, int silently);
void dest_obj(object obj);
//add akai 2006
int info(object env)
{
	string *dirs,df;
	mapping exits;

	if( mapp(exits = env->query("exits")) )
		dirs = keys(exits);

	if(sizeof(dirs)==1 && sizeof(dirs)!=0)
		write(TMI("bnway "+dirs[0]+";"));
	else if(sizeof(dirs)!=0)
		write(TMI( sprintf("bnway "+"%s;",implode(dirs[0..sizeof(dirs)], ";")) ));
        return 1;
}

// max_items is the maximum number of items an object can hold.
// note this is for non-character items.
// there is no limitations on # of characters. (limited by encumb)
// this is to prevent some rooms that full of items and
// players and npcs can't even enter. :P
static int max_items=10; // default max_items.
nomask void set_max_items(int e) {max_items=e;}
nomask int query_max_items() {return max_items;}
nomask int is_magic_move() { return magic_move; }
nomask int set_magic_move() { magic_move = 1; }
nomask int query_encumbrance() { return encumb; }
nomask int over_encumbranced() { return encumb > max_encumb; }

nomask int query_max_encumbrance() { return max_encumb; }
nomask void set_max_encumbrance(int e) { max_encumb = e; }
nomask void add_encumbrance(int w)
{
  encumb += w;
  if( encumb < 0 )
   log_file("move.bug", file_name(this_object())+
   this_object()->query("id")+
   " encumbrance underflow. env:"+file_name(environment())
   +" w:"+w+"\n");
//   log_file("move.bug", sprintf("%O encumbrance underflow.\n", this_object()));
  if( encumb > max_encumb ) this_object()->over_encumbrance();
  if( environment() ) environment()->add_encumbrance(w);
}

void over_encumbrance()
{
  if( !userp(this_object()) ) return;
  tell_object(this_object(), "你的负荷过重了！\n");
}

nomask int query_weight() { return weight; }
nomask void set_weight(int w)
{
  if( !environment() ) {
   weight = w;
   return;
  }
  if( w!=weight ) environment()->add_encumbrance( w - weight );
  weight = w;
}


// This is the "current" weight of an object, which is used on weight
// checking in move().
nomask int weight() { return weight + encumb; }

string ride_suffix (object me)
{
 string ridemsg = 0;
 object ridee = 0;

 ridee = me->ride();
 if (ridee)
  ridemsg = ridee->query("ride/msg")+"在"+ridee->name()+"上";
 return ridemsg;
}

// silently=1: no look.
// silently=2: only room name. (for follow)
// silently=0: full look.
// mon 4/20/98
varargs int move(mixed dest, int silently)
{
	//object user;
  if(_move(dest, silently)) return 1;
  
  call_out("dest_obj", 2, this_object());
  //tell_object(user, ADD0(this_object()));
  return 0;
}

// destruct obj if it failed to move and has no environment.
void dest_obj(object obj)
{
  if(obj && !environment(obj))
  destruct(obj);
}

varargs int _move(mixed dest, int silently)
{
  object ob, env, *inv, me;
  int i;
  mapping exits;
  string str="", str1="", *dirs,icon;
  string ridemsg="";
  me=this_object();




  // If we are equipped, unequip first.
  if( query("equipped") && !this_object()->unequip() )
   return notify_fail("你没有办法取下这样东西。\n");

  // Find the destination ob for moving.
  if( objectp(dest) )
   ob = dest;
  else if( stringp(dest) ) {
//   call_other(dest, "???");
// by mon 10/29/97. remove call_other, use load_object to find and load.
   ob=load_object(dest);
   if(!ob) 
    return notify_fail("move: destination unavailable.\n");
  } else
   return notify_fail(sprintf("move: invalid destination %O.\n", dest));

  // check for max_items.
  if(!(me->is_character()) &&
   sizeof(all_inventory(ob))>=ob->query_max_items()) {
    if(ob==this_player())
   return notify_fail("你身上装不下更多东西了。\n");
    else if(userp(ob))
   return notify_fail(ob->name()+"身上装不下更多东西了。\n");
    else { // for rooms and container.
   string name=ob->name();
   if(!name) name=ob->query("short");
   if(!name) name=ob->short();
   return notify_fail(name+"已经太拥挤了。\n");
    }
  }

  // Check if the destination ob can hold this object.
  // Beforce checking it, we check if the destination is environment of
  // this_object() (or environment of its environment). If it is, then
  // this could be like get something from a bag carried by the player.
  // Since the player can carry the bag, we assume he can carry the this
  // object in the bag and encumbrance checking is unessessary.
  env = this_object();

    if(env==ob) return notify_fail("你不能把物品放入自身之中。\n");
  //mon 8/25/97

  while(env = environment(env)) if( env==ob ) break;

  if( !env && (int)ob->query_encumbrance() + weight()
   > (int)ob->query_max_encumbrance() ) {
   if( ob==this_player() )
    return notify_fail( this_object()->name() + 
     "对你而言太重了。\n");
   else
    return notify_fail( this_object()->name() + 
     "对" + ob->name() + "而言太重了。\n");
  }

  // Move the object and update encumbrance
  // by snowcat 3/10/1998
  if( environment() ) 
  {
   environment()->add_encumbrance( - weight());
   if (userp(environment()) &&
       this_object()->value() >= 10000)
        environment()->save();
  }
  ob->add_encumbrance(weight());

  //added by snowcat
  if (userp(ob) && this_object()->value() >= 1000000)
  {
      object where1, where2;
      string place_me = "某";
      string place_ob = "某";

   where1 = environment();
      if (where1)
       place_me = (where1->short()?where1->short():where1->query("short"))+"["+file_name(where1)+"]";
   where2 = environment(ob);
      if (where2)
       place_ob = (where2->short()?where2->short():where2->query("short"))+"["+file_name(where2)+"]";
      if (where1 != ob)
       MONITOR_D->report_system_object_msg (ob,"（在"+place_ob+"）自"+
           place_me+"处得到了价值为"+to_chinese(this_object()->value()/10000)+"gold的巨款。");
  }

  move_object(ob);
    if(!this_object()) return 0; //mon 8/24/97

  // If we are players, try look where we are.
  if( interactive(this_object())   // are we linkdead?
  &&  living(this_object())    // are we still concious?
  &&  silently!=1 ) 
  if (silently==2 || this_object() -> query("env/brief_all"))
   tell_object(this_object(), environment()->query("short") ? environment()->query("short")+"\n": "\n");
  else {
   str = sprintf( "%s - %s\n  %s%s",
    environment()->query("short") ? environment()->query("short"): "",
    wizardp(me)? file_name(environment()): "",
    ( (!this_object() -> query("env/brief")) && (environment()->query("long")) ) ? environment()->query("long"): "",
    ( (!this_object() -> query("env/brief")) && (environment()->query("outdoors")) ) ? NATURE_D->outdoor_room_description(): "");

      if( mapp(exits = environment()->query("exits")) ) {
          dirs = keys(exits);
          for(i=0; i<sizeof(dirs); i++)
              if( (int)environment()->query_door(dirs[i], "status") & DOOR_CLOSED )
                  dirs[i] = 0;
        dirs -= ({ 0 });
          if( sizeof(dirs)==0 )
              str += "  这里没有任何明显的出路。\n";
          else if( sizeof(dirs)==1 )
              str += "  这里唯一的出口是 " + BOLD + dirs[0] + NOR + "。\n";
          else
              str += sprintf("  这里明显的出口是 " + BOLD + "%s" + NOR + " 和 " + BOLD + "%s" + NOR + "。\n",
          implode(dirs[0..sizeof(dirs)-2], "、"), dirs[sizeof(dirs)-1]);
      }
      //add akai 2006
      info(environment());//设置方向
         if(si==0)
  {
  I_CMD->main(me,me->query("couple/child"));//调用I命令更新装备栏
  si=1;

  }
  write(CLEAN0);
     inv = all_inventory(environment());
      i=sizeof(inv);
      while(i--) {
          if( !me->visible(inv[i]) ) continue;
          if( inv[i]==me ) continue;
          if (ridemsg = ride_suffix(inv[i]))
              str1 = " " + inv[i]->short() + " <"+ridemsg +">\n"+str1;
          else

               if(userp(inv[i])) icon=( inv[i]->query("gender") == "男性" )?"01174":"01173";
		else if(living(inv[i])) icon = "00901";
		else
             if(strsrch(inv[i]->short(),"Corpse",-1)!=-1)
                icon="00632";
                 else
                 icon = "00961";

                str1 = TMI("lbadd0 "+inv[i]->short()+icon+";") + "\n"+str1;
      } 
      
    
   tell_object(this_object(), str+str1);

  }

    // the following is made by snowcat on 6/20/1997
  // modified by mon 8/29/97
    if ((this_object()->query("is_monitored") ||
    file_name(this_object())[0..2]=="/u/") 
    && userp(ob))
      MONITOR_D->report_system_object_msg (ob,"得到了"+
       this_object()->query("name")
    +"("+file_name(this_object())+")。");
    //Modify By JackyBoy@TOMUD 2002/1/6

	if(!wizardp(this_object())||!query("env/invisible"))
	{
		if (env)
		{
			env->add_encumbrance(weight());
			if(userp(env)) tell_object(env,REM1(this_object()) ); //如果是从玩家身上移动走，则应该是REM1
			else if(!living(env)) tell_room(env,REM0(this_object()),this_object() );//如果是从房间里移动走，则应该是REM0
			//else log_file("move.log",ctime(time())+"：不知道如何显示REM消息---"+base_name(env)+"\n");
		}
		if (ob)
		{
			ob->add_encumbrance(weight());
			if(userp(ob)||interactive(ob)) tell_object(ob,ADD1(this_object()) ); //如果是移动到玩家身上，则应该是ADD1
			else if(!ob->is_character()) tell_room(ob,ADD0(this_object()),this_object() );//如果是移动到房间里，则应该是ADD0
		}
	}

  return 1;
}




void remove(string euid)
{
   	object me;
	object ob;
  object default_ob;
   ob = environment();
  if( !previous_object()
  ||  base_name(previous_object()) != SIMUL_EFUN_OB )
   error("move: remove() can only be called by destruct() simul efun.\n");
 	me = this_object();//akai
  if( userp(this_object()) && euid!=ROOT_UID ) {
   log_file("destruct", sprintf("%s attempt to destruct user object %s (%s)\n",
    euid, this_object()->query("id"), ctime(time())));
   error("你(" + euid + ")不能摧毁其他的使用者。\n");
  } else if( this_object()->query("equipped")) {
   if(  !this_object()->unequip() )
    log_file("destruct", sprintf("Failed to unequip %s when destructed.\n",file_name(this_object())));
  }

  // We only care about our own weight here, since remove() is called once
  // on each destruct(), so our inventory (encumbrance) will be counted as
  // well.
  if( environment() )  environment()->add_encumbrance( - weight );
  		//Add By JackyBoy@TOMUD      2001/5/27
		if(userp(ob))
			tell_object(ob,REM1(ob) ); //如果是从玩家身上移动走，则应该是REM1
		else if(!living(ob)&&!ob->is_character())
			tell_room(ob,REM0(ob),ob );//如果是从房间里移动走，则应该是REM0
			
			
  if( default_ob = this_object()->query_default_object() )
   default_ob->add("no_clean_up", -1);
}









int move_or_destruct( object dest )
{
  if( userp(this_object()) ) {
   tell_object(this_object(),
    "一阵时空的扭曲将你传送到另一个地方．．．\n");
   move(VOID_OB);
  }
}

object ride ()
{
 object me = this_object();
 string ridemsg = "";
 object ridee;

 if (ridee = me->query_temp("ridee")) {
  if ((environment(ridee) != environment(me) &&
     environment(ridee) != me) ||
    (ridee->is_character() && ! living(ridee))) {
   me->set_temp("ridee",0);
   ridee->set_temp("rider",0);
   ridee = 0;
  }
 }
 if (! ridee) {
  me->add_temp("apply/dodge",-me->query_temp("ride/dodge"));
  me->set_temp("ride/dodge",0);
 }
 return ridee;
}

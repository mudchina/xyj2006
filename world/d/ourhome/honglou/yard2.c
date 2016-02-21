// Room: /u/mon/poem/yard by mon@xyj 5/9/97
inherit ROOM;
#include <ansi.h>;

int POEMS=319;
string this_place="/d/ourhome/honglou/yard2";
//need to change above line if this room is moved to another place.

string author,title,*poem;
string author1,title1,*poem1;
int length,length1,running;
string current,current_all,last,last_all;
string curr_show;
int index,chance;
int poem_index,answerd,ans_curr,ans_last;

void new_poem();
void copy_to_old();
void do_test();
void do_init(object me);
void poem_reward(object me,string arg);
void poem_reward1(object me);
void poem_penalty(object me);
int find_newline();
string enscript(string arg);


void create ()
{
  set ("short", "蘅芜院");
  set ("long", @LONG

　　　　蘅芜满静苑，萝薜助芬芳。软衬三春草，柔拖一缕香。
　　　　轻烟迷曲径，冷翠滴回廊。谁谓池塘曲？谢家幽梦长。


栏杆外另放着两张竹案，一个上头设着茶筅茶盂各色茶具，一个上面摆着
笔墨纸砚。当中一张大纸上，墨迹未干，龙飞凤舞地写着些什么(poem)。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"miner.c",
  "east":__DIR__"lihuashu.c",
  "south" : __DIR__"cave",
  "north" : __DIR__"main",
]));

  set("no_fight", 1);
  set("no_magic", 1);

  set("objects", ([
    __DIR__"npc/poemgirl": 1,
  ]));

  setup();

  remove_call_out("do_test");
  poem_index=1;
  running=0;

}

void init()
{   
     add_action("do_answer","answer");
     add_action("do_author","author");
     add_action("do_look","look");
     
     call_out("do_init",1,this_player());

     if(running==0) {
       running=1;
       new_poem();
       copy_to_old();
       new_poem();
       call_out("do_test",2);
     }
}

void do_init(object me)
{ 
    tell_object(me,"\n探春告诉你：你可以用answer <...>来对诗句，author <...>来回答作者姓名。\n\n");
    return;
}

int do_author(string arg)
{   object me=this_player();
    
    if(!arg) return notify_fail("作者是谁？\n");

    if( living(me) ) me->receive_damage("sen",5+random(15));

    arg=replace_string(arg," ","");
    if(me->query_temp("poem/index")!=poem_index ) 
      return notify_fail("只有对出诗句后才能回答作者是谁。\n");

    if(answerd==1) return
      notify_fail("别人已经回答过这首诗的作者了。\n");
      
    message_vision("$N说道：这首诗的作者是"+arg+"？\n",me);
    if(arg==author) { 
         answerd=1;
         write("探春说道：对了！\n");
         poem_reward1(me);
    } else {
      me->add_temp("poem/wrong",1);
      if(me->query_temp("poem/wrong")>20) poem_penalty(me);
    }
    return 1;
}

int do_answer(string arg)
{ 
    object me=this_player();

    if(!arg) return notify_fail("回答什么？\n");

    if( living(me) ) me->receive_damage("sen",5+random(15));

    arg=replace_string(arg," ","");
    switch(random(2)) {
     case 0: message_vision("$N说道：可是．．．"+arg+"？\n",me);
             break;
     case 1: message_vision("$N答道："+arg+"？\n",me);
             break;
    }
    if(arg==current&&strlen(current)>2) {
      if(ans_curr==1) {
       write("别人已经回答过这句诗了。\n");
       return 1;
      }
      ans_curr=1;
      
      //change to a new poem once this one is answered.
      index=length-1;

      me->set_temp("poem/index",poem_index);
      poem_reward(me,current_all);
    } else if(arg==last&&strlen(last)>2) {
      if(ans_last==1) {
       write("别人已经回答过这句诗了。\n");
       return 1;
      }
      ans_last=1;
      poem_reward(me,last_all);
    } else {
      write("探春摇了摇头：好象不对吧？\n");
      me->add_temp("poem/wrong",1);
      if(me->query_temp("poem/wrong")>20) poem_penalty(me);
    }

    return 1;
}

void poem_penalty(object me)
{
    message_vision("忽然一阵狂风卷起，把$N吹得无影无踪了．．．\n",me);
    if(!me->query("dream_place")) me->move("/d/city/kezhan");
    else me->move((string)me->query("dream_place"));
    write("你睁开眼来，才知不过是南柯一梦，不过，又有些头痛．．．\n");
    me->set("sen",-1);
    me->set_temp("poem/wrong",0);

    return;
}

void poem_reward(object me,string arg)
{
    me->set_temp("poem/wrong",0);
    message_vision("探春点头道：“"+arg+"”好诗！好诗！\n",me);
    poem_reward1(me);
}

void poem_reward1(object me)
{  
	int dx,pot,lite;
    switch(random(3)) {
     case 0: dx=3+random(6);
             me->add("daoxing",dx);
	     message_vision("$N的道行增加了！\n",me);
	     break;
     case 1: pot=2+random(3);
	     if(me->query("potential")+pot-me->query("learned_points")<=100)
               me->add("potential",pot);
             message_vision("$N的潜能增加了！\n",me);
	     break;
     case 2: lite=3+random(6);
             me->improve_skill("literate",lite);
	     message_vision("$N的读书识字进步了！\n",me);
	     break;
    }
    me->add("poem_answered",1);
    dx=me->query("poem_answered");
    if((dx-dx/10*10)==0) {
      message_vision("$N倏地化为一股清烟，随即飘散不见了．．．\n",me);
      if(!me->query("dream_place")) me->move("/d/city/kezhan");
      else me->move((string)me->query("dream_place"));
      if(me->query("startroom")==this_place)
        me->set("startroom","/d/city/kezhan");
      me->save();
      message_vision("$N一觉醒来，睁开了眼，梦中所见似乎还历历在目．．．\n",me);
    }
}

void do_test()
{  
   int newt;
   string first,second,quest;

   if(strlen(current)>2&&ans_curr==0) {
     last=current;
     last_all=current_all;
     ans_last=0;
   }
   
   newt=0;
   while(newt==0) {
    if(!find_newline()) {
     copy_to_old();
     new_poem();
    } else {
      if(sscanf(poem[index],"%s  %s",first,second)==2 &&
       !sscanf(poem[index],"%*s［") && 
       !sscanf(poem[index],"%*s（") &&
       !sscanf(poem[index],"%*s□") ) {
         if(strlen(first)>2&&strlen(second)>2) {
	   newt=1;
         } 
      }
    }
   }

   first=replace_string(first," ","");
   second=replace_string(second," ","");
   current_all=first+"  "+second;
   ans_curr=0;
   if(random(2)==0) {
     quest=enscript(first);
     current=second;
     curr_show=quest+enscript("．．．");
     switch(random(2)) {
       case 0: 
         tell_room(this_object(),"探春道：“"+quest+"”的后半句是什么？\n");
         break;
       case 1:
         tell_room(this_object(),"探春说："+quest+"．．．后面是什么来着？\n");
         break;
     }
   } else {
     quest=enscript(second);
     current=first;
     curr_show=enscript("．．．")+quest;
     switch(random(2)) {
       case 0:
         tell_room(this_object(),"探春问道：“"+quest+"”的前半句是什么？\n");
	 break;
       case 1:
         tell_room(this_object(),"探春自言自语：．．．"+quest+"？前面是什么来着？\n");
	 break;
     }
   }

   if(sizeof(filter_array(all_inventory(this_object()), (:userp:))))
       call_out("do_test",60);
   else
       running=0;
   return;
}

int do_look(string arg)
{   int i;

    if(!arg || arg!="poem") return 0;

    write("\n\n    "+author1+"："+title1+"\n");
    for (i=0;i<length1;i++) {
      write("    "+poem1[i]+"\n");
    }
    write("\n\n\n");

    write(enscript("当前题目：　　　")+curr_show+"\n\n");

    return 1;

}

void copy_to_old()
{    int i;
     author1=author;
     title1=title;
     length1=length;
     poem1=({});
     last="";
     for (i=0;i<length;i++)
       poem1+=({poem[i]});
     return;
}

void new_poem()
{   string filename,buf;
    int i,j,k;

    length=0;
    while (length==0) {
    while((k=(1+random(POEMS)))==poem_index);
    filename=__DIR__"poem/poem"+k;
    buf=read_file(filename,1,1);
    sscanf(buf,"%s：%s",author,title);
    i=0;
    j=0;
    poem=({});
    while(buf=read_file(filename,2+i,1)) {
      if(strlen(buf)>2) {
        buf=replace_string(buf,"\n","");
        poem+=({buf});
	j++;
      }
      i++;
    }
    length=j;
    }
    poem_index=k;
    answerd=0;
    index=-1;
    chance=3*100/(1+length);
    if(length<3) {
      chance=100;
    }
    return;
}

int find_newline()
{
   index++;
   while(index<length) {
     if(random(100)<chance) {
       return 1;
     } else index++;
   }
   return 0;
}

string enscript(string arg)
{    string result;
     string *color=({BLK,RED,GRN,YEL,BLU,MAG,CYN,WHT,
                     HIR,HIG,HIY,HIB,HBRED,HBGRN,HBYEL,
		     HBBLU,HBMAG,BBLK,BRED,BGRN});
     int len,i;

     len=sizeof(color);
     result="";
     i=sizeof(arg);
     while(i>2) {
       if(random(2)==0) {
         result=color[random(len)]+NOR+arg[i-2..i-1]+result;
       } else {
         result=arg[i-2..i-1]+result;
       }
       i-=2;
     }
     result=NOR+arg[0..1]+result;

     return result;
}


// Room: /changan/phomes
//cglaem...12/31/96.
//mon. 2/23/97.

inherit ROOM;

void create ()
{
  set ("short", "住宅区");
  set ("long", @LONG

泾水之滨的一块住宅区，沿河坐落着一栋栋漂亮的小别墅。
这里风光旖旎，气息清新，正是住家的绝好所在。几座小楼
前挂着牌子(paizi)，写着些人家的名字。

LONG);
  set("exits", ([ /* sizeof() == 3 */
  "south" :__DIR__"wside5",
]));

  setup();
}

void init()
{
        add_action("show_name", "look");
	add_action("enter_home","",1);
}

int show_name(string arg)
{     
      mixed *files; 
      string who,result,content,chinese;
      int n,i,j,k;

      if(!arg||arg!="paizi") return 0;
      files=get_dir("/d/changan/playerhomes/");
      n=sizeof(files);
      j=0;
      for(i=0;i<=n-1;i++) {
	if(sscanf(files[i], "h_%s.c", who)==1) {
	  files[j]=who;
	  ++j;
        }
      }
      result="";
      if (j>0) {
	--j;
	k=0;
	for (i=0;i<=j;i++) {
	  content=read_file("/data/user/"+files[i][0..0]+
	    "/"+files[i]+".o");
          if(content){
            if(sscanf(content,"%*s\"name\":\"%s\"",
	      chinese)==2) {
	      result+=sprintf("  %-10s：%-16s  ",files[i],chinese);
	      if(k==1) result+="\n";
	      k=1-k;
            }
          }
        }
      }
      write("\n                        玩家之家 \n");
      write("\n"+result+"\n");
      
      return 1;
}

int enter_home(string arg)
{     
      string name,*files;
      object me=this_player();

      name=query_verb();
      files=get_dir("/d/changan/playerhomes/");
      if(member_array("h_"+name+".c",files)>-1) {
	message_vision("$N轻轻打开一扇门，走了进去。\n",me);
        me->move("/d/changan/playerhomes/h_"+name);
	return 1;
      }
      else return 0;
	
}


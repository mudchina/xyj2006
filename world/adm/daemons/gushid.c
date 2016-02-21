//潜能股票市场
//write by yesi for dtxy
//yeahsi@21cn.com

#include <ansi.h>

inherit F_SAVE;
void change_gushi();
string check_output(mapping check_gupiao);
string status_color(int i);

string *gupiao_name=({"南城客栈",
                     "董记当铺",
                     "回春药铺",
                     "长安乐坊",
                     "长安鞋帽店",
                     "老孙皮货店",
                     "三联书局",
                     "喜福会",
                     "长安兵器铺",
                     "南湾竹屋",
                     "翠香楼",
                     "金亭馆",
                     "烟花院",
                     "春醇茶栈",
                     "七里酒楼",
                     "蔬菜市场",
                     "首饰店",
                     "羊肉店",
                     "坤元客栈",
                     "四季水果店",
                   });
                                      
string query_save_file() { return DATA_DIR + "gushid"; }

mapping gupiao;

//status--- 0:无升跌，1:升，2:涨停，-1:跌，-2:跌停
void create()
{
    int i;
    seteuid(getuid());
    if ( !restore() && !mapp(gupiao) )
     {  gupiao = ([]);
        for (i=0;i<20;i++)
          {     
              if( undefinedp( gupiao[gupiao_name[i]] ) )
               gupiao[gupiao_name[i]]=(["price":50,
                                        "highest":50,
                                        "lowest":50,
                                        "status":0
                                       ]);
          }
    save();
     }
    call_out("change_gushi",120);
}

//如果升，幅度不会超过15%,如果跌，幅度不会超过20%
void change_gushi()
{
	int i,i_or_d,range,price;
		
	for (i=0;i<20;i++)
          { i_or_d=random(3);//0--无变化，1--升
            price = gupiao[gupiao_name[i]]["price"];
            
            if (i_or_d == 0)  
              {gupiao[gupiao_name[i]]["status"]=0;
               continue;
              }
            
            if (i_or_d == 1)
              {range = 1+random(15);
               if (range >9) gupiao[gupiao_name[i]]["status"]=2;
               else gupiao[gupiao_name[i]]["status"]=1;
	       price = price + price*range/100;
	       gupiao[gupiao_name[i]]["price"] = price;
	       if (price > gupiao[gupiao_name[i]]["highest"])	       
              	  gupiao[gupiao_name[i]]["highest"] = price;
              	continue;
              }
              
            if (i_or_d == 2)
              {range = 1+random(15);
               if (range >9) gupiao[gupiao_name[i]]["status"]= -2;
               else gupiao[gupiao_name[i]]["status"]= -1;
	       price = price - price*range/100;
	       gupiao[gupiao_name[i]]["price"] = price;
	       if (price < gupiao[gupiao_name[i]]["lowest"])	       
              	  gupiao[gupiao_name[i]]["lowest"] = price;
              }	   
            }
      save();      
      call_out("change_gushi",120);
}                             


string gushi_list(string name)
{
	string output,temp;
	mapping check_gupiao;
	int i;
	output="股票名称        价格     历史最高价    历史最低价
-----------------------------------------------------\n";
	
	if (name)
	 {if (!gupiao[name]) return "没有这个股票。\n";
	  else output +=name+"     "+check_output(gupiao[name]);
	 }
	else
	 {for (i=0;i<20;i++)
	  output +=sprintf("%-10s %s\n",gupiao_name[i],"     "+check_output(gupiao[gupiao_name[i]]));
         }
                
         return output;
}

string check_output(mapping check_gupiao)
{
	string output,output_price;
	int status,price,highest,lowest;
	status = check_gupiao["status"];
	price = check_gupiao["price"];
	highest = check_gupiao["highest"];
	lowest = check_gupiao["lowest"];

        output=sprintf("%s%4|d"NOR"        %3d           %3d",
               status_color(status),price,highest,lowest);
        return output;
}                          	
	
string status_color(int i)
{
	if (i==0) return NOR;
	if (i==1) return HIR;
	if (i==2) return BRED;
	if (i==-1) return HIB;
	if (i==-2) return BBLU;
}
	
	 	
#include<stdio.h>
#include <stddef.h>

enum event {
	APP_PASSIVE_OPEN, APP_ACTIVE_OPEN, APP_SEND, APP_CLOSE,
  APP_TIMEOUT, RCV_SYN, RCV_ACK, RCV_SYN_ACK, RCV_FIN, RCV_FIN_ACK
};

enum state {
	ERROR, CLOSED, LISTEN, SYN_SENT, SYN_RCVD, ESTABLISHED,
  CLOSE_WAIT, LAST_ACK, FIN_WAIT_1, FIN_WAIT_2, CLOSING, TIME_WAIT,
};




typedef struct state_evt_node
{
    enum state current_state;
    enum event coming_evt;
    enum state next_state;

}t_state_evt_node;

t_state_evt_node state_evt_map[]={
    // closed
    {
        .current_state = CLOSED,
        .coming_evt=APP_PASSIVE_OPEN,
        .next_state=LISTEN,
    },
     {
        .current_state = CLOSED,
        .coming_evt=APP_ACTIVE_OPEN  ,
        .next_state=SYN_SENT,
    },

    // Listen
    {
        .current_state = LISTEN,
        .coming_evt=RCV_SYN  ,
        .next_state=SYN_RCVD,
    },
        {
        .current_state = LISTEN,
        .coming_evt=APP_SEND           ,
        .next_state=SYN_SENT,
    },
        {
        .current_state = LISTEN,
        .coming_evt=APP_CLOSE          ,
        .next_state=CLOSED,
    },
    // SYN_RCVD
            {
        .current_state = SYN_RCVD,
        .coming_evt=APP_CLOSE                 ,
        .next_state=FIN_WAIT_1,
    },
        {
        .current_state = SYN_RCVD,
        .coming_evt=RCV_ACK                  ,
        .next_state=ESTABLISHED,
    },
    //SYN_SNED
    {
        .current_state = SYN_SENT,
        .coming_evt=RCV_SYN                  ,
        .next_state=SYN_RCVD,
    },
    {
        .current_state = SYN_SENT,
        .coming_evt=RCV_SYN_ACK                      ,
        .next_state=ESTABLISHED      ,
    },
    {
        .current_state = SYN_SENT,
        .coming_evt=APP_CLOSE                        ,
        .next_state=CLOSED,
    },
    //ESTABLISHED
     {
        .current_state = ESTABLISHED,
        .coming_evt=APP_CLOSE                           ,
        .next_state=FIN_WAIT_1,
    },
     {
        .current_state = ESTABLISHED,
        .coming_evt=RCV_FIN                             ,
        .next_state=CLOSE_WAIT,
    },
    //FIN_WAIT_1
         {
        .current_state = FIN_WAIT_1,
        .coming_evt=RCV_FIN                                   ,
        .next_state=CLOSING,
    },
         {
        .current_state = FIN_WAIT_1,
        .coming_evt=RCV_FIN_ACK                               ,
        .next_state=TIME_WAIT,
    },
         {
        .current_state = FIN_WAIT_1,
        .coming_evt=RCV_ACK                                   ,
        .next_state=FIN_WAIT_2,
    },
    //CLOSING
             {
        .current_state = CLOSING,
        .coming_evt=RCV_ACK                                            ,
        .next_state=TIME_WAIT,
    },
    //FIN_WAIT_2
                 {
        .current_state = FIN_WAIT_2,
        .coming_evt=RCV_FIN                                                  ,
        .next_state=TIME_WAIT,
    },

    //TIME_WAIT
                     {
        .current_state = TIME_WAIT,
        .coming_evt=APP_TIMEOUT                                                     ,
        .next_state=CLOSED,
    },
    //CLOSE_WAIT
                         {
        .current_state = CLOSE_WAIT,
        .coming_evt=APP_CLOSE                                                         ,
        .next_state=LAST_ACK,
    },
        //LAST_ACK
                         {
        .current_state = LAST_ACK,
        .coming_evt=RCV_ACK                                                                 ,
        .next_state=CLOSED,
    },
};

enum state get_TCP_state (size_t n, const enum event events[n])
{
    //initial state
    // for(int x =0; x< sizeof(state_evt_map)/sizeof(t_state_evt_node);x++)
    // {
    //     state_evt_map[x].current_state == CLOSED
    // }

    enum state next_state;


    if( state_evt_map[0].coming_evt == events[0])
    {
        next_state = state_evt_map[0].next_state;
    }
    else if(state_evt_map[1].coming_evt == events[0])
    {
          next_state = state_evt_map[1].next_state;
        /* code */
    }else 
    {
        return ERROR;
    }

    for(int y=0, x =1; x<n; x++)
    {
        for( y =0; y< sizeof(state_evt_map)/sizeof(t_state_evt_node); y++)
        {
            if((state_evt_map[y].current_state == next_state)&&
                (state_evt_map[y].coming_evt == events[x]))
            {
                next_state = state_evt_map[y].next_state;
                break;
                }
        }

        if(sizeof(state_evt_map)/sizeof(t_state_evt_node) == y)
        
        {
            printf("x =%d, next_state=%d\r\n", x,next_state);
            return ERROR;
            
        }

    }

	return next_state;
}


const enum event event1[]={1,3,7,5,0,7};


int main()
{

    // for(int x = 0; x< sizeof(event1)/sizeof(event1[0]);x++)
    //     printf(" event: %d\r\n",event1[x]);

    // printf(" sizeof(event1)= %d\r\n",sizeof(event1)/sizeof(int));

    // printf("hello world");

    printf("STATE =%d\r\n",get_TCP_state(6,event1));

    return 0;
}
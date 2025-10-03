class Node{
    int data;
    Node prox;
}

class Queue{
    int size;
    int limit;
    Node head;
    Node tail;
}

class QueueService {

    public Queue constructQueue(int limit){
        Queue queue = new Queue();
        queue.head = null;
        queue.tail = null;
        queue.size = 0;

        if (limit <= 0){
            limit = 99999;
        }
        queue.limit = limit;

        return queue;
    }

    public boolean Enqueue(Queue q, Node node){
        if (q == null || node == null){
            return false;
        }

        if (q.size >= q.limit){
            return false;
        }

        node.prox = null;
        if(q.size == 0){
            q.head = node;
            q.tail = node;
        }else{
            q.tail.prox = node;
            q.tail = node;
        }

        q.size++;

        return true;
    }

    public Node Dequeue(Queue q){
        Node node;
        if(q.size == 0){
            return null;
        }

        node = q.head;
        q.head = (q.head).prox;
        q.size--;

        return node;
    }
}
class Main {
    public static void main(String[] args){
        int i, value;
        Node node;
        QueueService service = new QueueService();

        Queue queue = service.constructQueue(10);

        for(int c = 0; c < 10; c++){
            node = new Node();
            value = 100 + c;
            System.out.printf("O numero %d esta entrando na fila.\n", value);
            node.data = value;
            service.Enqueue(queue, node);
        }

    }
}
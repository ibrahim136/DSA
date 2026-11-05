#include <iostream>
#include "Circular_Queue/Circular_Queue.h" 
#include "Double_Ended_Queue/Double_Ended_Queue.h" 



int main() {
    std::cout << "========== Circular Queue Tests ==========\n";
    Circular_Queue Q_C(5);
    Q_C.Enqueue(10);
    Q_C.Enqueue(20);
    Q_C.Enqueue(30);
    Q_C.Enqueue(40);
    Q_C.Enqueue(50);
    std::cout << "Queue contents: ";
    Q_C.display();

    Q_C.Enqueue(60);

    std::cout << "Dequeued: " << Q_C.dequeue() << std::endl; 
    std::cout << "Dequeued: " << Q_C.dequeue() << std::endl;
    std::cout << "Queue contents after dequeue: ";
    Q_C.display(); 
    std::cout << "Current Size: " << Q_C.Get_Size() << std::endl;

    Q_C.Enqueue(60); 
    Q_C.Enqueue(70);
    std::cout << "Queue contents after enqueuing: ";
    Q_C.display();

    std::cout << "Front Element: " << Q_C.Get_Front() << std::endl; 
    std::cout << "Rear Element: " << Q_C.Get_Rear() << std::endl;

    while (!Q_C.IsEmpty()) {
        std::cout << "Dequeued: " << Q_C.dequeue() << std::endl;
    }
    std::cout << "Queue contents after emptying: ";
    Q_C.display();

    Q_C.dequeue();
    Q_C.Get_Front();
    Q_C.Get_Rear();  

    std::cout << "\n\n========== Double Ended Queue Tests ==========\n";
    Double_Ended_Queue Q_EQ(5);
    
    Q_EQ.Enqueue_Rear(10);
    Q_EQ.Enqueue_Rear(20);
    Q_EQ.Enqueue_Front(30);
    Q_EQ.Enqueue_Front(40);
    Q_EQ.Enqueue_Rear(50);
    std::cout << "Queue contents (Enqueue Front/Rear): ";
    Q_EQ.display(); 
    std::cout << "Current Size: " << Q_EQ.Get_Size() << "\n";

    Q_EQ.Enqueue_Front(60);
    Q_EQ.Enqueue_Rear(70);

    std::cout << "Dequeued Front: " << Q_EQ.Dequeue_Front() << std::endl;
    std::cout << "Dequeued Rear: " << Q_EQ.Dequeue_Rear() << std::endl;
    std::cout << "Queue contents after dequeues: ";
    Q_EQ.display(); 
    std::cout << "Current Size: " << Q_EQ.Get_Size() << "\n";

    Q_EQ.Enqueue_Rear(80);
    Q_EQ.Enqueue_Front(90);
    std::cout << "Queue contents after wrapping: ";
    Q_EQ.display(); 

    std::cout << "Front Element: " << Q_EQ.Get_Front() << std::endl; 
    std::cout << "Rear Element: " << Q_EQ.Get_Rear() << std::endl;   

    while (!Q_EQ.IsEmpty()) {
        std::cout << "Dequeued Rear: " << Q_EQ.Dequeue_Rear() << std::endl;
    }
    std::cout << "Queue contents after emptying: ";
    Q_EQ.display();

    Q_EQ.Dequeue_Front();
    Q_EQ.Dequeue_Rear();
    Q_EQ.Get_Front();
    Q_EQ.Get_Rear();

    return 0;
}
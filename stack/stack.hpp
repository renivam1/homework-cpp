#include <cstring>

struct Node {
  char* data;
  Node* next = nullptr;
};

struct Stack {
  Node* head = nullptr;
  size_t size = 0;
};

void Push(Stack* stack, const char* str) {
  Node* newNode = new Node;
  newNode->data = new char[std::strlen(str) + 1];
  std::strcpy(newNode->data, str);
  newNode->next = stack->head;
  stack->head = newNode;
  stack->size++;
}

void Pop(Stack* stack) {
  if(stack->size == 0) {
    return;
  }
  Node* tmp = stack->head;
  stack->head = stack->head->next;
  delete[] tmp->data;
  delete tmp;
  stack->size--;  
}

char* Top(const Stack* stack) {
  if(stack->size == 0) return nullptr;
  return stack->head->data;
}

size_t Size(const Stack* stack) {
  return stack->size;
}

void Clear(Stack* stack) {
  while(stack->size != 0) {
    Pop(stack);
  }
}

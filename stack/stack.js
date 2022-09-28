class Stack {
  constructor() {
    this.items = [];
    this.count = 0;
  }

  push(element) {
    this.items[this.count] = element;

    console.log(`${element} added to ${this.count}`);
    this.count += 1;

    return this.count - 1;
  }

  pop() {
    if (this.isEmpty()) {
      return undefined;
    }

    this.items[this.count - 1] = undefined;
    this.count -= 1;

    console.log(`${this.items[this.count - 1]} removed`);

    return this.items[this.count - 1];
  }

  peek() {
    console.log(`The top element is ${this.items[this.count - 1]}`);

    return this.items[this.count - 1];
  }

  isEmpty() {
    console.log(this.count === 0 ? "Stack is empty" : "Stack is not empty");

    return this.count === 0;
  }

  size() {
    console.log(this.count === 1 ? `${this.count} element in stack` : `${this.count} elements in stack`);

    return this.count;
  }

  print() {
    let str = ''
    for (let i = 0; i < this.count; i++) {
      str += this.items[i] + ' '
    }
    return str
  }

  clear() {
    this.items = [];
    this.count = 0;

    console.log("Stack cleared");

    return this.items;
  }
}

module.exports = Stack;

# Factory Method Pattern

**Purpose:**  
The Factory Method Pattern defines an interface for creating an object but lets subclasses alter the type of objects that will be created. It helps in decoupling the client code from the object creation code.

**When to Use:**  
- When a class cannot anticipate the class of objects it needs to create.
- When a class wants its subclasses to specify the objects it creates.
- To localize the logic to instantiate a complex object.

## Study the Pattern Structure

**Factory Method Class:**  
Defines an interface for creating an object but allows subclasses to alter the type of objects that will be created.

**Client:**  
Uses the Factory Method to create an instance of the desired class.

## Analyze the Pattern

**Benefits:**

- Flexibility: Allows the code to be more flexible and reusable by decoupling the creation code from the actual object.
- Scalability: Easy to introduce new document types without modifying the client code.

**Drawbacks:**

- Complexity: Increases the number of classes and can introduce complexity if overused.
#include <stdio.h>
#include <stdlib.h>

void ajoute(int codes[], int quantities[], int *numProducts, int code, int quantity, int maxProducts) {
    for (int i = 0; i < *numProducts; i++) {
        if (codes[i] == code) {
            quantities[i] += quantity;
            printf("Quantity added to existing product.\n");
            return;
        }
    }

    if (*numProducts < maxProducts) {
        codes[*numProducts] = code;
        quantities[*numProducts] = quantity;
        (*numProducts)++;
        printf("Product added to stock.\n");
    } else {
        printf("Error: Maximum number of products reached.\n");
    }
}

 void removeProduct(int codes[], int quantities[], int numProducts, int code, int quantity) {
     for (int i = 0; i < numProducts; i++) {
         if (codes[i] == code) {
             if (quantity > quantities[i])
                 printf("Error: Cannot remove more quantity than available in stock.\n");
             else {
                 quantities[i] -= quantity;
                 printf("Quantity removed from stock.\n");
             }
             return;
         }
     }
     printf("Error: Product not found in stock.\n");
 }

void displayStock(int codes[], int quantities[], int numProducts) {
    printf("Stock Total:\n");
    for (int i = 0; i < numProducts; i++) {
        printf("Product Code: %d, Quantity: %d\n", codes[i], quantities[i]);
    }
}

int main() {
    int codes[50];
    int quantities[50];
    int numProducts = 0;
    int maxProducts = 50;

    // Example usage:
    int productCode, productQuantity;

    // Add a product
    printf("Enter product code: ");
    scanf("%d", &productCode);

    printf("Enter product quantity: ");
    scanf("%d", &productQuantity);

    ajoute(codes, quantities, &numProducts, productCode, productQuantity, maxProducts);

    // Display the stock
    printf("\n1 - Stock after adding a product:\n");
    displayStock(codes, quantities, numProducts);

    // Remove a product
    printf("\n2 - Enter product code to remove: ");
    scanf("%d", &productCode);  

    printf("* Enter quantity to remove: ");
    scanf("%d", &productQuantity);

    removeProduct(codes, quantities, numProducts, productCode, productQuantity);

    // Display the stock after removal
    printf("\nStock after removing a product:\n");
    displayStock(codes, quantities, numProducts);

    return 0;
}



const cartItems = document.getElementById('cart-items');
const totalPrice = document.getElementById('total-price');
const checkoutButton = document.getElementById('checkout-btn');


let cart = JSON.parse(localStorage.getItem("cart")) || [];


function updateCart() {
    cartItems.innerHTML = ''; 
    let total = 0;

    if (cart.length === 0) {
        cartItems.innerHTML = '<p>Your cart is empty</p>';
        totalPrice.innerText = '$0.00';
        return; 
    }

    cart.forEach((item, index) => {
        const itemElement = document.createElement('div');
        itemElement.style.margin= '10px';
        itemElement.innerHTML = `
            <p>
                <strong>${item.name}</strong> - $${item.price}
                <button class="remove-btn" data-index="${index}">Remove</button>
            </p>
        `;        const removeButton = document.createElement('button');
        removeButton.innerText = 'Remove';


        cartItems.appendChild(itemElement);
        total += parseFloat(item.price);

    });


    document.querySelectorAll('.remove-btn').forEach(button => {
        button.addEventListener('click', (e) => {
            const index = e.target.getAttribute('data-index');
            removeItem(index);
        });
    });

    totalPrice.innerText = '$' + total.toFixed(2);



}

function removeItem(index) {
    cart.splice(index, 1);
    localStorage.setItem("cart", JSON.stringify(cart));
    updateCart();
}


updateCart();
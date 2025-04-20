







let lastScrollY = window.scrollY;

const header = document.querySelector("header");

window.addEventListener("scroll", () => {
    if (window.scrollY > lastScrollY) {
        header.style.top = "-100px"; 
    }
    else {
        header.style.top = "0"; 
    }
    lastScrollY = window.scrollY;  
});






cart = JSON.parse(localStorage.getItem("cart")) || [];
let CartCount = cart.length;

const cartCountElement = document.getElementById("cart-count");
if (cartCountElement) {
    cartCountElement.innerText = CartCount;
}


const addtoCartButtons = document.querySelectorAll(".add-to-cart");
addtoCartButtons.forEach(button => {
    button.addEventListener("click", () => {
        const productCard = button.closest(".product-cards");
        const Pname = productCard.querySelector("h2").innerText;
        const price = productCard.querySelector("p").innerText;
        const Pprice = price.replace("$", "").trim(); 


        cart.push({
            name: Pname,
            price: Pprice,
        });

        localStorage.setItem("cart", JSON.stringify(cart));
        cartCountElement.innerText = cart.length;
    });
});




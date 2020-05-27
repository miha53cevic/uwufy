window.onload = () => {
    init();
};

function init() {

    $('.button').on('click', function() {
        let data = $('#before').get(0).value;
        
        // Uwufy the text
        data = data.replace(/th/g, 'd');
        data = data.replace(/l/g, 'w');
        data = data.replace(/r/g, 'w');
        data = data.replace(/ou/g, 'uw');
        data = data.replace(/ohh/g, 'uh');
        data = data.replace(/Th/g, 'D');
        data = data.replace(/TH/g, 'D');
        data = data.replace(/L/g, 'W');
        data = data.replace(/R/g, 'W');
        data = data.replace(/Ohh/g, 'Uhh');
        data = data.replace(/OU/g, 'UW');

        $('#after').val(data);
    });
}
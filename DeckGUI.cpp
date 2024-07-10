#include "../JuceLibraryCode/JuceHeader.h"
#include "DeckGUI.h"

//==============================================================================
DeckGUI::DeckGUI(DJAudioPlayer* _player, 
                AudioFormatManager & 	formatManagerToUse,
                AudioThumbnailCache & 	cacheToUse
           ) : player(_player), 
               waveformDisplay(formatManagerToUse, cacheToUse)
{

    /** Make buttons visible and add colours to each of them */
    addAndMakeVisible(playButton);
    playButton.setColour(TextButton::ColourIds::buttonColourId, Colours::limegreen);
    addAndMakeVisible(stopButton);
    stopButton.setColour(TextButton::ColourIds::buttonColourId, Colours::firebrick);
    addAndMakeVisible(loopButton);
    loopButton.setColour(TextButton::ColourIds::buttonColourId, Colours::darkgrey);
    
    addAndMakeVisible(loadButton);
    loadButton.setColour(TextButton::ColourIds::buttonColourId, Colours::darkorange);
       
    /** Make sliders visible, use rotary sliders instead of linear sliders for speed and volume */
    addAndMakeVisible(volSlider);
    volSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 100, 20);
    volSlider.setSliderStyle(Slider::Rotary);
    // default volume is 0.5
    volSlider.setValue(0.5);
    
    addAndMakeVisible(speedSlider);
    speedSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 100, 20);
    speedSlider.setSliderStyle(Slider::Rotary);
    // default speed is 1.0
    speedSlider.setValue(1.0);

    addAndMakeVisible(waveformDisplay);

    addAndMakeVisible(posSlider);
    posSlider.setTextBoxStyle(juce::Slider::TextBoxAbove, false, 100, 20);
    addAndMakeVisible(posLabel);
    // adding text label for the position slider
    posLabel.setText("Position", dontSendNotification);
    posLabel.attachToComponent(&posSlider, true);

    /** adding listeners to the buttons */
    playButton.addListener(this);
    stopButton.addListener(this);
    loopButton.addListener(this);
    
    loadButton.addListener(this);

    /** adding listeners to the sliders */
    volSlider.addListener(this);
    speedSlider.addListener(this);
    posSlider.addListener(this);

    /** set range for the sliders */
    volSlider.setRange(0.0, 1.0);
    speedSlider.setRange(0.0, 10.0);
    posSlider.setRange(0.0, 1.0);

    startTimer(1);

    /** make the memo space visible */
    addAndMakeVisible(textEditor);

}

DeckGUI::~DeckGUI()
{
    stopTimer();
}

void DeckGUI::paint (Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (Colours::white);
    g.setFont (14.0f);
    g.drawText ("", getLocalBounds(),
                Justification::centred, true);   // draw some placeholder text
    
    /** Draw orange rectangle to distinguish memo spaces from the background  */
    g.setColour (juce::Colours::grey);
    g.fillRect (0, getHeight() * 3/4, getWidth(), 20);
}

void DeckGUI::resized()
{
    double deckHeight = getHeight() * 3/4;
    double rowH = deckHeight / 8;
    
    loadButton.setBounds(0, 0, getWidth(), rowH);
    playButton.setBounds(0, rowH, getWidth()/3, rowH);
    stopButton.setBounds(getWidth()/3, rowH, getWidth()/3, rowH);
    loopButton.setBounds(getWidth() * 2/3, rowH, getWidth()/3, rowH);
    volSlider.setBounds(0, rowH * 2, getWidth()/2 - 25, rowH * 2);
    speedSlider.setBounds(getWidth()/2, rowH * 2, getWidth()/2 - 25, rowH * 2);
    waveformDisplay.setBounds(0, rowH * 4, getWidth(), rowH * 3);
    posSlider.setBounds(75, rowH * 7, getWidth() - 150, rowH);
    
    textEditor.setBounds(0, deckHeight + 20, getWidth(), getHeight() * 1/4 - 20);
    
}

void DeckGUI::buttonClicked(Button* button)
{
    if (button == &playButton)
    {
        std::cout << "Play button was clicked " << std::endl;
        // play the music
        player->start();
    }
    if (button == &stopButton)
    {
        std::cout << "Stop button was clicked " << std::endl;
        // pause the music
        player->stop();

    }
    if (button == &loopButton)
    {
        std::cout << "Stop button was clicked " << std::endl;
        // move to the starting position
        player->setPositionRelative(0);
        // make sure the music starts to play if the button is clicked
        player->start();
    }
    if (button == &loadButton)
    {
        auto fileChooserFlags = 
        FileBrowserComponent::canSelectFiles;
        fChooser.launchAsync(fileChooserFlags, [this](const FileChooser& chooser)
        {
            player->loadURL(URL{chooser.getResult()});
            // load for the waveform display as well
            waveformDisplay.loadURL(URL{chooser.getResult()}); 
        });
    }
}

void DeckGUI::sliderValueChanged (Slider *slider)
{
    if (slider == &volSlider)
    {
        // change the volume
        player->setGain(slider->getValue());
    }

    if (slider == &speedSlider)
    {
        // change the speed
        player->setSpeed(slider->getValue());
    }
    
    if (slider == &posSlider)
    {
        // change the position
        player->setPositionRelative(slider->getValue());
    }
    
}

bool DeckGUI::isInterestedInFileDrag (const StringArray &files)
{
  std::cout << "DeckGUI::isInterestedInFileDrag" << std::endl;
  return true; 
}

void DeckGUI::filesDropped (const StringArray &files, int x, int y)
{
  std::cout << "DeckGUI::filesDropped" << std::endl;
  if (files.size() == 1)
  {
    player->loadURL(URL{File{files[0]}});
  }
}

void DeckGUI::timerCallback()
{
    //std::cout << "DeckGUI::timerCallback" << std::endl;
    waveformDisplay.setPositionRelative(
            player->getPositionRelative());
}


    

